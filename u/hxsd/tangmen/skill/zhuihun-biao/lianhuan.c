// ������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("��ʹ�õ��������ԡ�\n");


	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	msg = HIY "$N�����ָ�ץ��ö�������ƺ�����������$n����" NOR;
	message_vision(msg, me);

	msg = HIB "����           ����    "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIR "����           ����   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIG "����           ����   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIC "����           ����   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
        target->apply_condition("tmzhuihun_poison",10);
	me->add("neili", -150);
      me->start_busy(2);

	return 1;
}
