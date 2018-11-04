// hunpofeiyang.c ���Ƿ���
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

//	skill = me->query_skill("hunyuan-zhang",1);

	if( !me->is_fighting() )
	    	return notify_fail("�����Ƿ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("��������������ߣ�\n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�û��Ƿ��\n");

	if( (int)me->query_skill("qishang-quan", 1) < 60)
		return notify_fail("������ȭ����Ϊ����������ʹ�û��Ƿ���! \n");

	if( me->query_skill_mapped("cuff") != "qishang-quan") 
		return notify_fail("��û�м�������ȭ���޷�ʹ�û��Ƿ��\n");
 
	msg = HIY "$N���һ����ʹ������ȭ�ľ��������Ƿ����˫ȭ������������$n��ȥ��\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$nֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->receive_wound("qi", qi_wound);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
