// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define PO "��" HIW "��������" NOR "��"

inherit F_SSERVER;


string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

   

        if (! target) target = offensive_target(me);
        if(me->is_busy())
        return notify_fail("��������æ��\n");
        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" PO "��\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < 220)
                return notify_fail("��ľ����񹦲�����죬����ʩչ" PO "��\n");

        if ((int)me->query_skill("force", 1) < 260)
                return notify_fail("����ڹ���������������ʩչ" PO "��\n");

        if ((int)me->query_skill("blade", 1) < 260)
                return notify_fail("��Ļ���������򲻹�������ʩչ" PO "��\n");

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("���������Ϊ���㣬����ʩչ" PO "��\n");

        if (me->query("neili") < 400)
                return notify_fail("��������������������ʩչ" PO "��\n");

        if (me->query_skill_mapped("blade") != "jiuyang-shengong") 
                return notify_fail("��û�м���������Ϊ����������ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "��Ȼ�������𣬰����һ����Х������ԴԴ������ӿ"
              "��" + weapon->name() + HIW "��ɲ�Ǽ䵶â��Ŀ��������£�����$n" HIW "��\n" NOR;

        me->add("neili", -150);
        ap = me->query_skill("force") + me->query_skill("force", 1);
        dp = me->query_skill("parry") + target->query_skill("force", 1);

        me->start_busy(2 + random(2));
        if (ap * 11 / 20 + random(ap) > dp)
        {
                damage = me->query_skill("force")*2;
                me->add("neili", -200);
target->add("qi",-damage/2);
		target->add("eff_qi",-damage/2);
        target->add("neili", -(damage/2 ));
        target->add("neili", -(damage/2 ));		
                msg += HIR "$n" HIR "ֻ����â��Ŀ������ԥ�䵽��â�Ѵ�͸$n" HIR "���壬��ʱ"
                "��Ѫ��ӿ����Ϣɢ�ҡ�\n" NOR;
        } else
        {
                msg += HIC "����$n" HIC "��͸$P" HIC "����֮�е���������"
                       "����㣬ȫ��Ӧ�����硣\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

string final(object me, object target, int damage)
{
        target->add("neili", -(damage / 4));
        target->add("neili", -(damage / 8));
        return  HIR "$n" HIR "ֻ����â��Ŀ������ԥ�䵽��â�Ѵ�͸$n" HIR "���壬��ʱ"
                "��Ѫ��ӿ����Ϣɢ�ҡ�\n" NOR;
}


