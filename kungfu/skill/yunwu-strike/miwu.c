// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ʮ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ֻ�ܿ���ʹ�á�\n");		

        me->add("neili",-200);

	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed") / 10 + 1;
	msg = HIR "$Nʹ�������Ʒ��еģ�ʮ������ݣ�˫�ƻ��裬��Ӱ�ܲ���������$n��" NOR;
	if( random(myexp * lvl) > yourexp )
	{
		message_vision(msg + "\n", me, target);
		msg = "���$n��$N���˸���æ���ң�\n";
		message_vision(msg, me, target);
		target->start_busy(4);
	}
	else
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
	return 1;
}
