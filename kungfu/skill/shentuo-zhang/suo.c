// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SUO "��" CYN "ѩ��ǧɽ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int ap, dp, damage;
        string msg, pmsg;
        string *limbs, limb;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(SUO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("shentuo-zhang", 1) < 150)
                return notify_fail("������ѩɽ�ƻ�򲻹�������ʩչ" SUO "��\n");

        if (me->query_skill_mapped("strike") != "shentuo-zhang")
                return notify_fail("��û�м�������ѩɽ�ƣ�����ʩչ" SUO "��\n");


        if ((int)me->query("neili", 1) < 200)
                return notify_fail("�����ڵ��������㣬����ʩչ" SUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Ц������һ����һ�С�ѩ��ǧɽ��������������ŭ"
              "����ӿ����������$n��\n" NOR;
        me->add("neili", -20);

        ap =  me->query_skill("strike");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
                
                pmsg = HIR "��ʱֻ�������꡹һ�����죬$n" HIR "��"
                        "�ؿ��߹Ǿ�Ȼ���˼�����\n" NOR;

target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);

                        msg +=HIR "��ʱֻ�������꡹һ�����죬$n" HIR "��"
                        "�ؿ��߹Ǿ�Ȼ���˼�����\n" NOR;
                                                   
                me->start_busy(1);
                me->add("neili", -50);
        } else 
        {
                msg += CYN "����$n" CYN "������$P"
                       CYN "����ͼ�����μ������㿪����һ�ơ�\n"NOR;
                me->start_busy(3);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);

        return 1;
}

