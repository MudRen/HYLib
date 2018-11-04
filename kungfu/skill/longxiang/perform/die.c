// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define DIE "��" WHT "�����" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp;
        int i, count;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIE "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("longxiang", 1) < 240)
                return notify_fail("��������������Ϊ����������ʩչ" DIE "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" DIE "��\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("��û�м������������Ϊȭ�ţ�����ʩչ" DIE "��\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��û�м������������Ϊ�ڹ�������ʩչ" DIE "��\n");


        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" DIE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ջ�˫�ƣ�ʩ�����ھ�ѧ��" NOR + WHT "�����"
              HIY "����˫���ٶȺ��ƣ��͹���$n" HIY "��\n" NOR;

        ap = me->query_skill("unarmed") + me->query("con") * 20; 
        dp = target->query_skill("parry") + target->query("dex") * 20; 

        if (me->query("max_neili") > target->query("max_neili") * 2)
        {
                msg += HIR "$n" HIR "ȫȻ�����赲������$N"
                       HIR "һȭ���÷������صĵ����ڵ��ϡ�\n" NOR;
                me->add("neili", -50);
                me->start_busy(1);

                message_combatd(msg, me, target);

                target->set("eff_qi", 1);
                target->set("eff_jing", 1);
                target->unconcious();

                return 1;
        } else
        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 10;
                msg += HIR "$n" HIR "��$P" HIR "����Ѹ��֮����һʱ��֪����"
                       "�������ֵ���������������\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "��$p" HIY "����Ѹ��֮�������ѷ�������"
                       "æ��������С�ĵֵ���\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        if (count> 200) count=200;
        me->add_temp("apply/attack", count);

        me->add("neili", -300);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) ==0 && ! target->is_busy())
                        target->start_busy(2);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);

        return 1;
}

