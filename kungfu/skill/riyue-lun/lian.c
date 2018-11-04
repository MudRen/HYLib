// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define LIAN "��" HIW "������ת" NOR "��"

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string wp, msg;
        int i, count;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" LIAN "��\n");

        if (me->query_skill_mapped("hammer") != "riyue-lun")
                return notify_fail("��û�м��������ַ�������ʩչ" LIAN "��\n");

        if ((int)me->query_skill("riyue-lun", 1) < 150)
                return notify_fail("�������ַ�����㣬����ʩչ" LIAN "��\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("����ڹ�����㣬����ʩչ" LIAN "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬����ʩչ" LIAN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" LIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wp = weapon->name();

        msg = HIY "$N" HIY "��Ŀ��ȣ�ʩչ�������ַ���" HIW "������ת"
              HIY "���񼼣���ؽ�����" + wp + HIY "����\n������������"
              "����â���໥������ѹ��$n" HIY "������ɷΪ���棡\n" NOR;
        message_combatd(msg, me, target);

        if ((int)me->query_skill("longxiang", 1) < 90)
                count = me->query_skill("force", 1) / 8;
        else
                count = me->query_skill("longxiang", 1) / 4;
if (count> 200) count=200;

        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if ( weapon->query("id") == "jin lun")
                {
                        switch (i)
                        {
                        case 0:
                                msg = WHT "ͻȻ�����ִ����½����з���"
                                      "����������һ����â��$n" WHT "��"
                                      "ȥ��\n" NOR;
                                break;
                        case 1:
                                msg = HIR "ͻȻ�����ִ����½����з���"
                                      "����������һ����â��$n" HIR "��"
                                      "ȥ��\n" NOR;
                                break;
                        case 2:
                                msg = YEL "ͻȻ��ͭ�ִ����½����з���"
                                      "����������һ����â��$n" YEL "��"
                                      "ȥ��\n" NOR;
                                break;
                        case 3:
                                msg = HIW "ͻȻ�����ִ����½����з���"
                                      "����������һ����â��$n" HIW "��"
                                      "ȥ��\n" NOR;
                                break;
                        default:
                                msg = HIY "ͻȻ����ִ����½����з���"
                                      "����������һ����â��$n" HIY "��"
                                      "ȥ��\n" NOR;
                                break;
                        }
                        message_combatd(msg, me, target);
                        COMBAT_D->do_attack(me, target, weapon, 30);
                } else
                        COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add("neili", -250);
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count );
        me->start_busy(2);
        return 1;
}


