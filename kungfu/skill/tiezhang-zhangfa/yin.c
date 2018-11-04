#include <ansi.h>
#include <combat.h>

#define YIN "��" HIR "����ĥ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int ap, dp, dd;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("tiezhang-zhangfa", 1) < 220)
                return notify_fail("�������Ʒ���򲻹�������ʩչ" YIN "��\n");

        if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa")
                return notify_fail("��û�м��������Ʒ�������ʩչ" YIN "��\n");

        if (me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û��׼�������Ʒ�������ʩչ" YIN "��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ����������ʩչ" YIN "��\n");

        if ((int)me->query("max_neili") < 3500)
                return notify_fail("���������Ϊ����������ʩչ" YIN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "ʩ�����ƾ�����" HIR "����ĥ"
              HIW "�������Ʋ��Ű��������Я����������$n"
              HIW "��ȥ��\n" NOR;  

        ap = me->query_skill("tiezhang-zhangfa") + me->query("str") * 6;
        dp = target->query_skill("parry") + target->query("con") * 5;
        dd = target->query_skill("dodge") + target->query("dex") * 5;

        if (ap / 2 + random(ap) > dp)
        {
                damage = ap / 2 + random(ap / 2);
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
target->apply_condition("tiezhang_yin",50);
                msg +=HIW "���Ǽ�$n" HIW "�ѱ�$N" HIW "�����ƾ�����Ҫ"
               "�������ɵû���һ��������֮����\n" NOR;

        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "�Ƴ���磬��֪"
                       "���к��ż�������������б��������\n" NOR;
        }

        msg += HIR "\n������$N" HIR "����һ���Ʒ��������ϯ"
               "����һ�����ˣ���$n" HIR "��ǰ��Ȼ���䡣\n" NOR;  

        if (ap / 2 + random(ap) > dd)
        {
                damage = ap / 2 + random(ap / 2);
                         target->add("qi",-damage);
		target->add("eff_qi",-damage);
target->apply_condition("tiezhang_yang",50);
                msg +=HIR "ֻ���͵�һ����$N" HIR "��������ܸ����"
               "$n" HIR "�ؿڣ�����������߹ǡ�\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "���ź�Х���������ۼ�$N" CYN
                       "������磬��æ��Ծ��ܿ�����\n" NOR;
        }
        me->start_busy(3);
        me->add("neili", -400);
        message_combatd(msg, me, target);
        return 1;
}

