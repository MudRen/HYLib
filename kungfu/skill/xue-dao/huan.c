// huan.c Ѫ����������Ӱ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("Ѫ����������Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((int)me->query_skill("xue-dao", 1) < 80)
		return notify_fail("���Ѫ������������죬����ʹ�á���Ӱ����\n");

        if (me->query("neili") < 60)
                return notify_fail("�����������������޷�ʹ�á���Ӱ����\n");

        if (me->query_skill_mapped("blade") != "xue-dao")
                return notify_fail("��û�м���Ѫ������������ʹ�á���Ӱ����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "ʹ��Ѫ�����������������е�" +
              weapon->name() + HIR "��÷ɿ죬�����㵶Ӱ����$n"
              HIR "��\n";

        me->add("neili", -50);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2)
        {
		msg += HIR "���$p" HIR "��$P" HIR "�ָ���æ���ң�"
                       "ֻ�ܽ����Ż��������ö���\n" NOR;
		target->start_busy((int)me->query_skill("blade") / 50 + 3);
	} else
        {
		msg += "����$p" HIR "������$P" HIR "����ͼ����"
                       "�����ţ�Ӧ�����硣\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
