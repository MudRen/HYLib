// xixueqingfu.c ��Ѫ����
 
#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;
        int extra;
	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hanbing-mianzhang",1);

	if( !(me->is_fighting() ))
		return notify_fail("����Ѫ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á���Ѫ���𡹡�\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ����������\n");

	if( skill < 60)
		return notify_fail("��ġ��������ơ��ȼ�����, ����ʹ�á���Ѫ���𡹣�\n");

	if( me->query_skill("dodge",1) < 150 )
		return notify_fail("����Ṧ�������޷����á���Ѫ���𡹣�\n");
 
	msg = HIC "$NͻȻ��ͬ����Ѫ���𡹣��۽�$n����ǰ���������$n���ʺ�ҧȥ��\n"NOR;
	message_combatd(msg, me, target );
 if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{

        extra = me->query_skill("jiuyang-shengong",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);

        msg =  HIR "��һҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "�ڶ�ҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIR "����ҧ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);    
        me->add_temp("apply/damage", -extra);

}
	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-200);

		msg = HIG "$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��\n"NOR;
		neili_wound = 500 + random(skill);
		if(neili_wound > target->query("qi"))
			neili_wound = target->query("qi");

		qi_wound = neili_wound / 3;
		if (target->query("qi") > neili_wound)
		target->add("qi",-neili_wound);
		if (target->query("eff_qi") > neili_wound)
		target->add("eff_qi",-neili_wound);
		me->start_busy(2);
	       me->add("qi",qi_wound);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�����ݣ�\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) me->fight_ob(target);

	return 1;
}
