// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YIN "��" HIY "���ӡ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(YIN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YIN "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("dashou-yin", 1);

        if (skill < 100)
                return notify_fail("��Ĵ���ӡ��Ϊ����������ʩչ" YIN "��\n");

        if (me->query("neili") < 150)
                return notify_fail("�����������������ʩչ" YIN "��\n");

        if (me->query_skill_mapped("hand") != "dashou-yin")
                return notify_fail("��û�м�������ӡ������ʩչ" YIN "��\n");

        if (me->query_skill_prepared("hand") != "dashou-yin")
                return notify_fail("��û��׼������ӡ������ʩչ" YIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����ׯ�أ�����Я�ž��糯$n" HIY "��Ȼ�ĳ�����"
              "�����ھ�ѧ�����ӡ����\n" NOR;

        ap = me->query_skill("hand");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                me->start_busy(2);
                damage = 150+me->query_skill("hand");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "���$p" HIR "�мܲ�������$P" HIR
                                           "��һ�´���������̣���Ѫ������\n" NOR;
        } else
        {
                me->add("neili", -40);
                msg += CYN "����$p" CYN "���Ų�æ������ļܿ���$P"
                       CYN "�Ľ��ӡ��\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}


