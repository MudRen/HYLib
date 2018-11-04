// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// sad.c ��Ȼ����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
object weapon;        
weapon=me->query_temp("weapon");

                 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("����Ȼ���꡹ֻ����ս���жԶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ȼ���꡹ֻ�ܿ���ʹ�á�\n");
                
        if ((int)me->query("neili") < 1500)
                return notify_fail("�������������\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) < 250)
                return notify_fail("�����Ȼ�����ƻ�򲻹����޷�ʩչ����Ȼ���꡹��\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ�������޷�ʩչ����Ȼ���꡹��\n");


        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("�����Ů�������̫ǳ��\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("�����Ů�����̫ǳ��\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("������޵������̫ǳ��\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("�����չ÷���̫ǳ��\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("�������������̫ǳ��\n");
       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIM "$N" HIM "һ����̾������ֹˮ����Ȼ���ˣ��ڲ���������"
              "��ʹ����" HIR "����Ȼ���꡻" HIM "��\n" NOR;

        ap = me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
        if (ap * 11 / 20 + random(ap) > dp)
        {
                count = ap / 10;
target->add("qi",-ap);
target->add("eff_qi",-ap);

                        msg +=HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� \n"
                                           NOR;
                msg += HIY "$n" HIY "��$P" HIY "��һ�б仯Ī�⣬�����"
                       "�������ɴ��һ��������������������\n" NOR;
        } else
        {
                msg += HIC "$n" HIC "����С��$P" HIC
                       "�����У���Ų������С���мܡ�\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);
        if (count> 200) count=200;
        me->add_temp("apply/attack", count);

        me->add("neili", -200);
        for (i = 0; i < 7; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(1);

                 COMBAT_D->do_attack(me, target, weapon, 1);
        }

        me->start_busy(3);
        me->add_temp("apply/attack", -count);

        return 1;
}
