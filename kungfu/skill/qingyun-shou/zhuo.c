#include <ansi.h>
#include <combat.h>

#define ZHUO "��" WHT "����׽Ӱ" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 50)
                return notify_fail("��������ֲ�����죬����ʩչ" ZHUO "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���Ϊ����������ʩչ" ZHUO "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" ZHUO "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = WHT "$N" WHT "����������ַ�������Ӱ����ʵʵ���ѱ���α����"
              "ȫ����$n" WHT "��\n" NOR;

 if (random(me->query("combat_exp")) > target->query("combat_exp") / 3)
        {
                me->start_busy(2);
                damage = me->query_skill("hand");
                damage = damage / 3 + random(damage / 3);
                target->add("qi",-damage);
		target->start_busy(5);
                msg +=HIR "$p" HIR "һʱ�������ʵ����$P"
                                           HIR "��Ӱ�������ţ���Ѫ������������Ϣ��\n" NOR;
                me->add("neili", -50);
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
