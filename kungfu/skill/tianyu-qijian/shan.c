// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SHAN "��" HIW "������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp, damage;
        string msg;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHAN "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("tianyu-qijian", 1) < 60)
                return notify_fail("��������潣������죬����ʩչ" SHAN "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ�����㣬����ʩչ" SHAN "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("�����ڵ��������㣬����ʩչ" SHAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����΢��������һ̽����ʱһ������������͸���������"
              "����$n" HIW "��\n" NOR;
        me->add("neili", -80);

        ap =me->query_skill("sword");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)

        {
                msg += HIR "$n" HIR "���һ������æ�мܣ���һ�±�ʧ���Ȼ���\n" NOR;
                target->start_busy((int)me->query_skill("tianyu-qijian", 1) / 100 + 2);
        } else
        {
                msg += CYN "����$p" CYN "���Ų�æ�������˴���"
                       "��ʵ����û���ܵ����Ӱ�졣\n" NOR;
                me->add("neili", -100);
                me->start_busy(1);
        }
        message_combatd(msg, me, target);

        return 1;
}

