#include <ansi.h>
#include <combat.h>

#define TAN "��" HIC "����̽��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TAN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("liuhe-zhang", 1) < 60)
                return notify_fail("��������Ʒ�������죬����ʩչ" TAN "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" TAN "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" TAN "��\n");

        if (me->query_skill_mapped("strike") != "liuhe-zhang") 
                return notify_fail("��û�м��������Ʒ�������ʩչ" TAN "��\n");

        if (me->query_skill_prepared("strike") != "liuhe-zhang")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" TAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "�Ĳ�����˫����������Ȼ�䵥��쬵�̽����һ�С�����"
              "̽���ơ���$n" HIC "��ǰ���䣡\n" NOR;

        if (random(me->query_skill("liuhe-zhang")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(2);
                damage = me->query_skill("liuhe-zhang");
                damage = damage / 2 + random(damage / 3);
                me->add("neili", -50);
                          target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "���$p" HIR "���ܲ�������$P" HIR
                                           "һ�������ؿڣ���ʱ������Ѫ����������"
                                           "��\n" NOR;
        } else
        {
                me->start_busy(2);
                me->add("neili", -30);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
