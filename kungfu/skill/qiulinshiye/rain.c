// tie@fengyun
#include <ansi.h>
#include <combat.h>


inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("biyun-xinfa",1);
	if ( extra < 50) return notify_fail("��ģ۱����ķ��ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���ʧ����\n");
	message_vision( HIY "$N������$nһ�ӣ����ŵ������˳�ȥ��\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("���$N���������Ĳ�֪����\n",target);
            target->apply_condition("ill_dongshang",55);
            target->apply_condition("ill_fashao", 55);
            target->apply_condition("ill_kesou", 55);
            target->apply_condition("ill_shanghan", 55);
            target->apply_condition("ill_zhongshu", 55);	
	target->start_busy(5);
	}
	else{
	msg = "��ϧ$N������$n����������ѸȻ������";
	me->start_busy(1);
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
