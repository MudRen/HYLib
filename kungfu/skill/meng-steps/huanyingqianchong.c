// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("meng-steps",1);
	if ( extra < 50) return notify_fail("��ģۻ��β����ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۻ�Ӱǧ�أ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision( HIR "$N����ӰͻȻһ��ʮ��ʮ��١��ٱ�ǧ��$n�类$N��ǧ�ػ�ӰΧס��\n" NOR ,me,target);
	if(random((int)me->query("combat_exp"))+(int)me->query("combat_exp")/4 > (int)target->query("combat_exp")/2)
	{
	message_vision(HIW "���$NĿѣ��ڣ��ľ�������\n"NOR,target);
	target->start_busy(3);
	}
	else{
	message_vision("���$N�������ţ�\n",target);
	me->start_busy(2);
	}
	return 1;
}

