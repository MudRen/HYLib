// tie@fengyun

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)

{

	string msg;

	int i, lmt, damage ;
	object weapon;

	
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");


	if( (int)me->query_skill("sword") < 90 ||

	    me->query_skill_mapped("sword") != "huanhua-jian")

		return notify_fail(HIW "��ġ�佻��������������ң��޷�ʹ�á�������ѩ����\n"NOR);

	if( (int)me->query_skill("huanhua-jian", 1) < 150 )
		return notify_fail(HIW "��ġ�佻��������������ң��޷�ʹ�á�������ѩ����\n"NOR);


	if ((int)me->query("neili",1) < 600)

		return notify_fail("��������������޷�ʹ�á�������ѩ����\n");		

	if( !target ) target = offensive_target(me);

	if( !target

	||	!target->is_character()

	||	!me->is_fighting(target) )

		return notify_fail(HIW "��������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	weapon = me->query_temp("weapon");

	msg = HIY  "$N��Хһ�������ж�Ю����֮ʽ�������͵ı������ߣ����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
	message_vision(msg,me,target);

        if( !target->is_killing(me) ) me->kill_ob(target);
		damage = me->query_skill("huanhua-jian",1) + (int)me->query_skill("guiyuan-dafa", 1);

		damage = damage - random( target->query_skill("dodge")/4 );



	lmt = random(5)+3;

	for(i=1;i<=lmt;i++)

	{

	msg =  HIW "$N���һ�����ӵ�"+chinese_number(i)+"����\n" NOR;

	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}

//      target->receive_wound("jing", random( damage/20 ));
	target->receive_damage("qi", 20 + random(damage));

//	target->receive_wound("qi", 20 + damage);

        me->add("neili", -500);

		

	me->start_busy(4);

	return 1;

}

