#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() )
		return notify_fail("��Ҫ��˭����������\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("��ı����ڹ�������죬���ܽ���������\n");

	if( (int)me->query_skill("liuyang-zhang", 1) < 20 )
		return notify_fail("�����ɽ�����Ʋ�����죬���ܽ���������\n");

	if (!objectp(obj=present("jiudai", me)))
           return notify_fail("������û�оƴ������ܻ���Ϊˮ��\n");

	if (me->query("neili")<200)
		return notify_fail("���������㡣\n");

       if (!target->query_condition("ss_poison"))
            return notify_fail("Ŀ��û������������\n");

	msg = CYN "$N����$n������Ϊˮ������������\n";
	me->add("neili",-200);
	me->start_busy(2);
	 target->apply_condition("ss_poison", 0);

		message_combatd(msg, me, target);
	return 1;
}
