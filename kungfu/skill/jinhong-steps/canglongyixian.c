// tie@fengyun
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
		return notify_fail("�۲���է�֣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("jinhong-steps",1) / 5;
	me->add_temp("apply/attack", extra);	
	msg = HIR  "$N����һת��ͻȻ���η���˫����������ڿ�һ���͵���$n�߳���" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);
	me->start_busy(1);
	return 1;
}
