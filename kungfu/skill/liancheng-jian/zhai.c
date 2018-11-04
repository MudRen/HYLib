#include <ansi.h>
#include <combat.h>

#define ZHAI "��" HIW "�Ʊ�ժ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level;
	string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" ZHAI "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((level = me->query_skill("liancheng-jian", 1)) < 100)
                return notify_fail("�����Ž���������죬����ʩչ" ZHAI "��\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ʩչ" ZHAI "��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ����������ʩչ" ZHAI "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" ZHAI "��\n");

        if (me->query_skill_mapped("sword") != "liancheng-jian")
                return notify_fail("��û�м������Ž���������ʩչ" ZHAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIW "$N" HIW "һ���������������ţ����²�����˲����$n" HIW "����"
              "��������ͼ����$n" HIW "�Ĺ��ơ�\n" NOR;

        me->add("neili", -30);
        if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
        {
		msg += HIR "���$p" HIR "ֻ��$P" HIR "���о��ȫȻ"
                       "�治��������ʵ�����Ƶ�ʱһ����\n" NOR;
                target->start_busy(level / 50 + 3);
	} else
        {
		msg += CYN "����$p" CYN "������$P" CYN "���Ƶ���·��"
                       "���Գ��У�˿����Ϊ������\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
