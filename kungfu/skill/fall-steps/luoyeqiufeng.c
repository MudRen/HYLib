// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("fall-steps",1);
	if ( extra < 90) return notify_fail("��ģ���粽�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����Ҷ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision("$N��̤�˷�������������е���Ҷ��Ʈ�첻����\n",me,target);
	if(random((int)me->query("combat_exp"))+(int)me->query("combat_exp")/4 > (int)target->query("combat_exp")/2)
	{
	message_vision("���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n",target);
	target->start_busy(3);
	}
	else{
	msg = "��ϧ$N������$n����������ѸȻ������";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
