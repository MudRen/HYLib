#include <ansi.h>
#include <combat.h>

#define HUI "��" HIR "�����л�" NOR "��"
#define HUIP "��" HIR "�����л�" HIW "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUI "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 380)
                return notify_fail("���ڹ���Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("��������Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 250)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" HUI "��\n");


        if ((int)me->query("neili") < 1000)
                return notify_fail("��������������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        // ��һ��
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("dodge") + target->query("dex") * 5;

        message_vision(HIW "\n��Ȼ$N" HIW "���μ���������һ�������ֺ���һ��"
                     "����$n" HIW "�����ǽ���ʮ����" HUIP "��\n��������֮��"
                     "˵���㵽������ɽ����֮����$n" HIW "��ӿ��ȥ������ʯ"
                     "���쾪�������ޱȡ�\n" NOR, me, target);

        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg =HIR "$P����һ�������ѻ���$p��ǰ��$p��"
                                          "���������ٱ��������С�\n" NOR;
        } else
        {
                msg = HIC "ȴ��$p����˫�ۣ�����Ӧ�ԣ�$P��"
                      "������ţ�뺣������жȥ��\n" NOR;
        }
        message_vision(msg, me, target);

        // �ڶ���
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("parry") + target->query("int") * 5;

        message_vision(HIW "\n$N" HIW "һ�Ƽȳ���������Ȼ������$n" HIW "��"
                     "����֮�⣬������ǰ�������������ϲ���\n����һ��" HUIP
                     "��������������ŭ����ӿ���Ʋ��ɵ�����ʱ$p�����Ϣ��"
                     "�ͣ����㲻�ȡ�\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = ap + random(ap / 2);
                                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg =HIR "$pһ���Һ�����$P��һ�ƻ�����ǰ��"
                                          "���꿦����˼����߹ǡ�\n" NOR;
        } else
        {
                msg = HIC "����$pȫ���ֵ��мܣ�����������"
                      "�࣬��$P������ж�����Ρ�\n" NOR;
        }
        message_vision(msg, me, target);

        // ������
        ap = me->query_skill("xianglong-zhang") + me->query("str") * 5;
        dp = target->query_skill("force") + target->query("con") * 5;

        message_vision(HIW "\n������$N" HIW "����б�ӣ�ǰ������δ����������"
                     "���ֵ�����Ȼ�ֹ���һ��" HUIP "��\n�Ƽз��ƣ���������"
                     "����һ��������ǽ����ǰ�����ȥ��$n" HIW "ֻ����Ѫ��"
                     "ӿ����Ϣ���ǡ�\n" NOR, me, target);

        if (ap *11 / 20 + random(ap) > dp)
        {
                damage = ap + random(ap);
                                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg =HIR "���$p����������$P�ƾ���ʱ���ض�"
                                          "������ʱ������Ѫ���硣\n" NOR;
        } else
        {
                msg = HIC "$p�ۼ��������ͣ����μ��ˣ�˲��"
                      "Ʈ�����ɣ��ѳ�����֮�⡣\n" NOR;
        }
        message_vision(msg, me, target);
        me->start_busy(3);
        me->add("neili", -300 - random(600));
        return 1;
}
