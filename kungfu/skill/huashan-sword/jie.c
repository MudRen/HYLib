// jie.c ��ɽ����������ʽ��
// MODIFY BY RCWIZ 2003

#include <ansi.h>

inherit F_SSERVER;

#define JIE "��" HIG "����ʽ" NOR "��"

int perform(object me, object target)
{
	object weapon;
        int level;
	string msg;

	if (! target) target = offensive_target(me);


	if (! target || ! me->is_fighting(target))
		return notify_fail(JIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (target->is_busy())
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
		
	if ((level = me->query_skill("huashan-sword", 1)) < 30)
		return notify_fail("��Ļ�ɽ����������죬�޷�ʩչ" JIE " ��\n");

        if (me->query_skill_mapped("sword") != "huashan-sword")
                return notify_fail("��û�м�����ɽ�������޷�ʩչ" JIE "��\n");

        if (me->query("neili") < 60)
                return notify_fail("�����������������޷�ʹ�á�����ʽ����\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n����$N" HIW "����һ�գ�ʹ����ɽ��������֮"
              "��" HIG "����ʽ" HIW "����ת��֮�������޷죬һ"
              "\n���ȳ�������ԴԴ��к�������Ծ̲����������Ѹ"
              "Ȼ����$n" HIW "��\n" NOR;

        me->add("neili", -50);
	if (random(level) > (int)target->query_skill("parry", 1) / 3)
        {
		msg += HIR "���$p" HIR "�᲻��������������"
                       "������һʱ���޷����֣�\n" NOR;
		target->start_busy(level / 50 + 3);
	} else
        {
                if (objectp(weapon = target->query_temp("weapon")))
        		msg += CYN "����$p" CYN "ʶ����$P" CYN "�����⣬"
                               "�Թ˽����е�" + weapon->name() +
                               CYN "\n���һ�Ź⻨��$P"
                               CYN "һ��֮����Ҳ������ȥ��\n" NOR;
                else
                        msg += CYN "����$p" CYN "˫�ִ�����ģ���$P"
                               CYN "������һһ�ܿ���\n" NOR;

		me->start_busy(1);
	}
	message_vision(msg, me, target);

	return 1;
}
