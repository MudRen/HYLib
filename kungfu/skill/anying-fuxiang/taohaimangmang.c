#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("anying-fuxiang",1);
	if ( extra < 90) return notify_fail("��ģ۰�Ӱ���㲽�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Һ�ãã��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     
        if( me->query_skill("bibo-shengong",1) < 80)
return notify_fail("��ı̲�����Ϊ���δ����ʩչ���Һ�ãã��ֻ���˼�����\n");

	if(target->is_busy())
		return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
	message_vision(HIM"$N������Ȼ�ӿ죬���ܶ���һ���һ��ƺ�����$n���費ͣ��\n"NOR,me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
	{
	message_vision("���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n",target);
	me->start_busy(1);
	target->start_busy(4);
	}
	else{
	me->start_busy(4);
	msg = "��ϧ$N������$n����������ѸȻ������";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
me->add("neili", -150);
	return 1;
}
