#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUI "��" HIW "����׶" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if (! target) target = offensive_target(me);

 

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if ((int)me->query_skill("tongbi-zhang", 1) < 90)
                return notify_fail("��ͨ�������Ʋ�����죬����ʩչ��\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHUI "��\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("�����������������޷�ʹ��" ZHUI "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "\n$N" HIY "һ����Ц��˫��һ����Ȼʩ��һ��"
              "��" HIW "����׶" HIY "�����ó�ǧ��֮����һ��"
              "����$n" HIY "��" NOR;

        if (random(me->query_skill("tongbi-zhang")) > target->query_skill("dodge") / 3)
        {
                me->start_busy(1);
                damage = me->query_skill("tongbi-zhang");
                damage = damage  + random(damage);
                me->add("neili", -150);
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n���$p" HIR "û�ܱܿ�$P" HIR
                                          "���Ī����Ʒ����ƾ���ʱ͸�ض�����"
                                          "������Ѫ������ˤ����\n" NOR;
        } else
        {
                me->start_busy(2);
                me->add("neili", -50);
                msg = CYN "\n����$p" CYN "ʶ����$P"
                      CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

