#include <ansi.h>
#include <combat.h>

#define ZHI "��" HIG "��ָ��ɽ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHI "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("qixing-shou", 1) < 60)
                return notify_fail("������ָ��������죬����ʩչ" ZHI "��\n");

        if ((int)me->query_skill("force") < 80)
                return notify_fail("���ڹ���Ϊ����������ʩչ" ZHI "��\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�����ڵ���������������ʩչ" ZHI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIG "$N" HIG "ббһָ�̳���ָ��ζ����ѣ�ңң����$n"
              HIG "ҪѨ���ڡ�\n" NOR;

        if (random(me->query_skill("hand")) > target->query_skill("parry") / 3)
        {
                me->start_busy(1);
                damage = me->query_skill("finger");
                damage = 40 + damage / 3 + random(damage / 4);
                me->add("neili", -60);
target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "���$p" HIR "�м�ʧ�󣬱�$P" HIR
                                           "��һָ���˸����ţ���Ϣ��ʱһ�ͣ���Ѫ������\n" NOR;
        } else
        {
                me->start_busy(2);
                me->add("neili", -20);
                msg += CYN "����$p" CYN "ʶ����$P"
                       CYN "��һ�У�ббһԾ�ܿ���\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
