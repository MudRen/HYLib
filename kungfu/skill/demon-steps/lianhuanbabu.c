// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("demon-steps",1);
	if ( extra < 30) return notify_fail("��ģ�������ħ�����˲��ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������˲���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision("$N�Ų�������������$nת����ͣ��\n",me,target);
	if(random((int)me->query("combat_exp"))+(int)me->query("combat_exp")/4 > (int)target->query("combat_exp")/2)
	{
	message_vision("���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n",target);
	target->start_busy(3);
	}
	else{
	message_vision("���$N�Լ�ת�˸�ͷ���ۻ���\n",me);
	me->start_busy(2);
	}
	return 1;
}
