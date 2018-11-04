// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// gu.c ��עһ��

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;

        damage = me->query_skill("strike");

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����עһ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á���עһ������\n");              

        if( (int)me->query_skill("huixin-strike", 1) < 60 )
                return notify_fail("��Ķ��Ҵ����Ʋ�����죬����ʹ�á���עһ����!\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���עһ����!\n");

        msg = CYN "$NĬ���񹦣�ʹ����"RED"��עһ��"CYN"����˫��ƽ�ƹ���$n��\n"NOR;

        ap = me->query_skill("strike");
        dp = target->query_skill("force");
             
        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(random(2));
                target->start_busy(random(3));

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);

                if( damage < 40 )
                        msg += HIY"���$n��$N˫�ƴ����ؿڣ��ƺ�һ����\n"NOR;
                else if( damage < 80 )
                        msg += HIY"���$n��$N��˫�ƴ����ؿڣ����١���һ������������\n"NOR;
                else if( damage < 160 )
                        msg += RED"���$n��$N��˫�ƴ����ؿڣ������ܵ�һ���ش�����������������\n"NOR;
                else
                        msg += HIR"���$n��$N��˫�ƴ����ؿڣ���ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
                
        }
        else 
        {
                me->start_busy(1 + random(2));
                msg += CYN"����$p������$P����ͼ������һת�����ƻػ���\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
