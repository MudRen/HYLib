// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIY "�ý���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, level;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN  "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUAN "��\n");
        
        if ((int)me->query_skill("tianyu-qijian") < 120)
                return notify_fail("��������潣������죬����ʩչ" HUAN "��\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("����ڹ�����㣬����ʩչ" HUAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" HUAN "��\n");
                        
        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        level = me->query_skill("tianyu-qijian", 1);
        
        msg = HIY "$N" HIY "����Ϣ�������󼲶������ǧ�������������ǵط���$n"
              HIY "��\n" NOR;

        message_combatd(msg, me, target);
        me->add("neili", -100);
        me->add("apply/attack", level / 5);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add("apply/attack", - level / 5);
        me->start_busy(1 + random(5));

        return 1;
}

