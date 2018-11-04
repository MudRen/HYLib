// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define TUN "��" HIR "������" NOR "��"

inherit F_SSERVER;

//nherit F_CLEAN_UP;


void remove_effect(object me);

int perform(object me, object target)
{
        object weapon;
        int ap, dp, foc, damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TUN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TUN "ֻ�ܿ���ʩչ��\n");

        if (me->query_temp("long_tun"))
                return notify_fail(TUN "�޷�����ʩչ��\n");

        if ((int)me->query_skill("longxiang", 1) < 180)
                return notify_fail("��������������Ϊ����������ʩչ" TUN "��\n");

        if (me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬����ʩչ" TUN "��\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("��û�м������������Ϊȭ�ţ�����ʩչ" TUN "��\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��û�м������������Ϊ�ڹ�������ʩչ" TUN "��\n");


        if (me->query("neili") < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" TUN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "˫�����ҷ��ţ��������죬��ʩ���������������ѧ��"
              HIR "������" HIY "������ʱ��\nХ������������һ�������ޱȵ��"
              "��$N" HIY "˫�Ƽ�ӿ�����ƹ���$n" HIY "��ȥ��\n" NOR;

        me->set_temp("long_tun", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me :), 50);

        ap = me->query_skill("unarmed")+ me->query_skill("force"); 
        dp = target->query_skill("dodge") + target->query_skill("force"); 

        if (ap / 2 + random(ap) > dp)
        {
                foc = target->query_skill("force");
                damage = ap / 2 + random(ap) + random(foc) + 150;
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "һ����������$N" HIR "���"
                                               "���������ţ������������Ĵ��Ҵܣ��Ҳ���"
                                               "�ԡ�\n" NOR;

                me->start_busy(3);
                me->add("neili", -300);
        } else
        {
                me->start_busy(3);
                me->add("neili", -200);
                msg += CYN "����$p" CYN "��$P" CYN "�������ƷǷ�����"
                       "æ���������ߣ����ڶ�ܿ�����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

void remove_effect(object me)
{
        if (me->query_temp("long_tun"))
        {
                me->delete_temp("long_tun");
                tell_object(me, "�㾭��������Ϣ���ֿ��Լ���ʩչ" TUN "�ˡ�\n");
        }
}


