// leiting.c  �������֡�����һ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("paiyun-shou", 1) < 100)
                return notify_fail("����������ֲ�����죬����ʹ�á�����һ������\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʹ�á�����һ������\n");

        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹����޷�ʹ�á�����һ������\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����������������޷�ʹ�á�����һ������\n");

        msg = HIG "$N" HIG "����������˫�ƣ�һ��ŭ�ȣ�˫����Ȼ��������$n" HIG "�Ƴ���\n" NOR;

        ap = (int)me->query_skill("paiyun-shou", 1) +
             (int)me->query_skill("force") +
             (int)me->query("str") * 10;

        dp = (int)target->query_skill("parry") +
             (int)target->query_skill("dodge") / 2 +
             (int)target->query("str") * 10;

        me->add("neili", -150);

        if (ap / 2 + random(ap) > dp || !living(target))
        {
                damage = (int)me->query_skill("force") + (int)me->query_skill("hand");
                damage = damage / 4;
                damage += random(damage);
    target->add("qi",-damage+100);
		target->add("eff_qi",-damage+100);
                msg += HIR "$n" HIR "���ܲ���������ǰ�أ�"
                                           HIR "ֻ�����ء���һ����$n"
                                           HIR "����һ����Ѫ��������ֽ�װ����ɳ���\n" NOR;
                me->start_busy(2); 
        } else
        {       msg += HIC "����$p" HIC "���з�����" HIC 
                       "����һ�����ܿ���$P" HIC "��һ����\n"NOR;
                me->start_busy(2); 
        }
        message_vision(msg, me, target);
        return 1;
}

