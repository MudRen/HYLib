// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	int qi;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ˮ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("liuquan-steps") / 10 + 1;
	msg = HIR "$Nʹ����Ȫ�����еģ���ˮ�����ݣ��ó�������Ӱ��ӰӰ����$n��" NOR;
	if( random(yourexp) < myexp * lvl)
	{
		message_vision(msg + "\n", me, target);
		msg = "���$n��$N���˸���������\n";
		message_vision(msg, me, target);
		qi = (int) target->query("qi");
		target->receive_damage("qi", qi/10);
	}
	else
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
	return 1;
}
