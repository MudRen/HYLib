// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUN "��" HIW "��ػ�Ԫ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp;
        int i, count;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("xiantian-qigong", 1) < 200)
                return notify_fail("������칦��Ϊ����������ʩչ" HUN "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" HUN "��\n");

        if (me->query_skill_mapped("unarmed") != "xiantian-qigong")
                return notify_fail("��û�м������칦Ϊȭ�ţ�����ʩչ" HUN "��\n");

        if (me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("��û�м������칦Ϊ�ڹ�������ʩչ" HUN "��\n");


        if(me->is_busy())
        return notify_fail("��������æ��\n");
        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" HUN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "ʩ����ػ�Ԫ��ȫ������������ת��������Χ������"
              "�����ѣ�������ӿ��$n" HIW "��\n" NOR;

        ap = me->query_skill("unarmed")+ me->query("con") * 20;
        dp = target->query_skill("parry") + target->query("dex") * 20;

        if (ap * 11 / 20 + random(ap) > dp)
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

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/defense", count);

        me->add("neili", -280);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(5) < 2 && ! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/defense", -count);

        return 1;
}
