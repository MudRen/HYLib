// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HAI "��" HIC "��Ԩʽ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HAI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(HAI "ֻ�ܿ���ʩչ��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" HAI "��\n");

        if ((int)me->query_skill("zhemei-shou", 1) < 130)
                return notify_fail("�����ң��÷�ֵȼ�����������ʩչ" HAI "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�������������㣬����ʩչ" HAI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIB "$N" HIB "���ּ��裬ʩ����ң��÷�֡���Ԩʽ�����ַ�"
              "��翣�����ʵʵ����$n" HIB "Ҫ����\n" NOR;

        me->add("neili", -50);
        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("hand") * 3;
                me->add("neili", -100);
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "��ʱ������Ӱ��Ϊһץ��$p" HIR "��"
                                           "�ܲ�������$N" HIR "��ָ�������ţ���Ѫ"
                                           "�Ĵ��ɽ���\n" NOR;


                me->start_busy(2);
        } else 
        {
                me->add("neili", -50);
                msg += HIC "����$p" HIC "�������ݣ����μ�ת������Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

