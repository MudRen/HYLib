// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("fengyu-piaoxiang",1);
	if ( extra < 70) return notify_fail("��ģ۷���Ʈ�㲽�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ݺ��ĺ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision( HIY "$N����ͻȻ�ӿ죬��ͬ�������������������ݺ��ĺ�֮���ƣ�\n" NOR ,me,target);
	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
	message_vision(HIB "���$N���ָ��ţ�һ��Īչ����\n"NOR,target);
	target->start_busy(5);
	}
	else{
	message_vision("���$N�������ţ�\n",target);
	me->start_busy(2);
	
	}
	return 1;
}

