#include <ansi.h>
#include <combat.h>

#define CHU "��" HIM "�����Ⱥ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CHU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(CHU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tongbi-zhang", 1) < 80)
                return notify_fail("��ͨ�������Ʋ�����죬����ʩչ" CHU "��\n");


        if (me->query_skill("force") < 80)
                return notify_fail("����ڹ���Ϊ����������ʩչ" CHU "��\n");

        if ((int)me->query("neili") < 120)
                return notify_fail("�����ڵ���������������ʩչ" CHU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");

        msg = HIC "\n$N" HIC "�ڿն���ʩչ�����С�" HIM "�����Ⱥ" HIC "����"
              "\n����һֻ�����ٿն��£�˫���͵�����$n" HIC "��\n" NOR;


        if (ap / 2 + random(ap) > dp)
        {
                damage = (int)me->query_skill("strike", 1);
                damage = damage+200+random(300);
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "����$N" HIR "˫���������Ʒ����죬"
                                           "����Ѹ���ޱȡ�$n" HIR "�پ��ľ���ս��"
                                           "�����м�֮����΢�����ɼ�$N" HIR "\n����"
                                           "������$n" HIR "�ؿڣ��ٽ�$p����������"
                                           " \n" NOR;
                me->start_busy(1);
                me->add("neili", -80);
        } else
        {
                msg = CYN "$n" CYN "��$N" CYN "��������������"
                      "��ӯ��ֻ�����һ�ݣ��Ŷ����һ�ơ�\n" NOR;

                me->start_busy(2);
                me->add("neili", -100);
        }
        message_vision(msg, me, target);
        return 1;
}
