// hua.c ��������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int extra;
	extra = me->query_skill("huagu-mianzhang",1);
	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !target || !target->is_character() )
		return notify_fail("���ֻ���ֻ�ܶԶ���ʹ�á�\n");

	if( target->query_temp("huagu")>3)
		return notify_fail("�����Ѿ����˲������ֻ����ˣ����ٴ�Ҳû���ˡ�\n");


	if( (int)me->query_skill("shenlong-xinfa", 1) < 50 )
		return notify_fail("��������ķ�������죬���ܻ��ǡ�\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 40 )
		return notify_fail("��Ļ������Ʋ�����죬���ܻ��ǡ�\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������������ܻ��ǡ�\n");

        me->add("neili", -100);

	msg = MAG "$N�Ƴ������������$n��ͷ�ϡ�\n"NOR;

	me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
{
		msg += MAG "���ֻ���˵�һ����$p��$Pһ�����У�\n" NOR;
		msg += MAG "$pֻ����ȫ��ů����ģ��е��е���Ʈ�����ᡣ\n" NOR;
		target->add_temp("apply/attack", -extra/5);
		target->add_temp("apply/dodge", -extra/5);
		target->add_temp("apply/defense", -extra/5);
		target->add_temp("huagu",1);
        target->apply_condition("snake_poison",10);
        target->apply_condition("cold_poison",10);
		msg += HIB "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$p����\n" NOR;
                me->start_call_out( (: call_other, __FILE__, "remove_effect",target,extra/5, extra/5:), extra/5);
}
	 else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(3);
	}

	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
void remove_effect(object target,int aamount, int damount)
{
if (target)
{
		target->add_temp("apply/attack", aamount);
		target->add_temp("apply/dodge", aamount);
		target->add_temp("apply/defense", aamount);
target->start_busy(3);
               message_combatd(YEL"$N�����ҵĹ����а����˳�������������,��ס�˽Ų�\n"NOR, target);
}
}
