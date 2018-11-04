// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHE "��" HIC "��÷ʽ" NOR "��"

inherit F_SSERVER;

 
int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail(ZHE "ֻ�ܿ���ʩչ��\n");

        skill = me->query_skill("zhemei-shou", 1);

        if (skill < 80)
                return notify_fail("�����÷�ֵȼ�����������ʩչ" ZHE "��\n");

        if (me->query_skill("force") < 120)
                return notify_fail("���ڹ���򲻹�������ʩչ" ZHE "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�������������㣬����ʩչ" ZHE "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIC "$N" HIC "����ң��÷�����仯Ϊһʽ����������ӳ�������"
              "ʵʵ����$n" HIC "ȫ���ҪѨ��\n" NOR;
 
        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        
        me->add("neili", -80);
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -50);
                msg += HIR "$n" HIR "��ͷһ�����벻���ƽ�֮������æ��"
                      "��������һʱ���޷�������\n" NOR;
                target->start_busy(ap / 100 + 2);
        } else
        {
                msg += CYN "����$p" CYN "�Ŀ�����$P" CYN "����ͼ��˿"
                      "����Ϊ��������$P" CYN "������û������κ����á�\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}

