// zhong.c ��������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼��ܡ�\n");

        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����������ֻ����ս����ʹ�á�\n");

	if( !target || !target->is_character() )
		return notify_fail("������ֻ�����ڶ������ϡ�\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("��ı����ڹ�������죬��������������\n");

	if (me->query("neili")<200)
		return notify_fail("���������㡣\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 40 )
		return notify_fail("�����ɽ�����Ʋ�����죬��������������\n");


	msg = CYN "$N��ˮΪ�����������У���ƮƮ������$n��\n";

	me->start_busy(1);

 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
 {
		msg += CYN " ���$p��$P���˸����ţ�\n" NOR;
		target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1));
		target->receive_wound("qi",155 + random( (int)me->query_skill("liuyang-zhang",1)));
		target->receive_wound("jing", 10);
		target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 30 +
		target->query_condition("ss_poison"));
		me->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(2);
		message_combatd(msg, me, target);
	}
        me->add("neili",-60);
// if target is not busy, then busy him (by xbd)
	if (!target->is_busy()) target->start_busy(1 + random(2));
//	if( !target->is_killing(me) ) target->kill_ob(me);
//	if(!target->is_fighting(me)) target->fight_ob(me);
//	destruct(obj);

	return 1;
}
