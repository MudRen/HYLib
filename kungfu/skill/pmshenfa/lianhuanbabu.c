// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("pmshenfa",1);
	if ( extra < 60) return notify_fail("��ģ�Ʈ�����ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������˲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision(HIC"$N�Ų���ħ ��ħ ��ħ ��������������$nת����ͣ��\n"NOR,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision(RED"���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n"NOR,target);
	target->start_busy(5);
	me->start_busy(1);
	}
	else{
	message_vision(YEL"���$N�Լ�ת�˸�ͷ���ۻ���\n"NOR,me);
	me->start_busy(1);
	}
	return 1;
}
