#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[�ƻ�]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߣ��������á��꼤÷������㡹��\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á��꼤÷������㡹��\n");

extra = me->query_skill("zimu-zhen",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*5);
msg = RED "$N����һ����Ŷ��Ű���----һ�������ŷ�ɥ�����ƻ���$n���˳�ȥ��\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*5);
        me->add("neili",-50);
	me->start_busy(1+random(2));
	target->apply_condition("zimu-zhen",random(10)+10);

return 1;
}

