// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiutian.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("liuyang-zhang", 1) < 120)
                return notify_fail("��������Ʒ�������죬����ʹ�á�����ʽ����\n");
                                
        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�����ʽ����\n");
                        
        if ((int)me->query("neili") < 300)
                return notify_fail("��������������������ʹ�á�����ʽ����\n");
                        
        msg = HIC "$N" HIC "˫��һ�񣬻���������Ӱ����������ס$n" HIC "��\n" NOR;

        ap = me->query_skill("strike"); 
        dp = target->query_skill("parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "���Σ�ֻ��Ӳ��һ�У������$P"
                                           HIR "���������������Ѫ��ֹ��\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += HIC "����$p" HIC "ǿ��������Ӳ�����ĵ�ס$P"
                       HIC "��һ�ƣ�û���ܵ��κ��˺���\n"NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
