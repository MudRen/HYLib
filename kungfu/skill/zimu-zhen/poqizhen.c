// poqizhen.c ������
 
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound,extra;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("zimu-zhen",1);

	if( !(me->is_fighting() ))
		return notify_fail("�������롹ֻ����ս�������ڶ������ϡ�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 100 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫����\n");


	if( skill < 80)
		return notify_fail("�����ĸ�뷨��������, ����ʹ�á������롹��\n");

	if( me->query("neili") < 150 )
		return notify_fail("��������������޷����á������롹��\n");

 extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*5);
msg = RED "$N����һ����Ŷ��Ű���----һ�������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*5);
        me->add("neili",-50);

	msg = HIY "$N��ָ�뵶��ָ��������ö����,Ǳ��������һʽ�������롹��ֱ��$n���ϡ��С��µ����ȥ��\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);
		msg = "$N�������롹����Ŀ��, $n��ʱ���õ�����һ���ʹ��\n";
		msg += "ȫ��������й������\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
		neili_wound = 500 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		target->add("qi", -qi_wound);
		target->add("eff_qi", -qi_wound);
		target->start_busy(2);
        target->apply_condition("tmpili_poison", 60);

//		me->start_busy(random(2));
	}
	else
	{
		if(userp(me))
			me->add("neili",-80);
		msg = "����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
