// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define RUO "��" HIW "����" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(RUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" RUO "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if ((int)me->query_skill("mingwang-jian", 1) < 100)
                return notify_fail("�㲻��������������죬����ʩչ" RUO "��\n");

        if (me->query_skill_mapped("sword") != "mingwang-jian")
                return notify_fail("��û�м�������������������ʩչ" RUO "��\n");

        if (me->query("neili") < 100)
                return notify_fail("�����ڵ��������㣬����ʩչ" RUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���е�" + weapon->name() + HIW "����ݳ���"
              "����һ��������$n" + HIW "�������в�����Щ��ã��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "��ͷһ��һʱ��Ȼ���Ե��У�������"
                       "����������\n" NOR;
                target->start_busy((int)me->query_skill("sword") / 80 + 2);
        } else
        {
                msg += HIC "����$n" HIC "����ֻ����΢һ�ͣ��漴���ѣ�û"
                       "�б�$P" HIC "�����š�\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

