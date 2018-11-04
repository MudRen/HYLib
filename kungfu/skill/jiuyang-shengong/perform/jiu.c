// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define JIU "��" HIR "���ػ���" NOR "��"

inherit F_SSERVER;

 
int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int count;
        int i;
 
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }



        if (! target || ! me->is_fighting(target))
                return notify_fail(JIU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(JIU "ֻ�ܿ���ʩչ��\n");
         if(me->is_busy())
        return notify_fail("��������æ��\n");               
        if (me->query("max_neili") < 6000)
                return notify_fail("�����������Ϊ�����������޷�ʹ��" JIU "��\n");

        if (me->query_skill("jiuyang-shengong", 1) < 200)
                return notify_fail("��ľ����񹦻�������죬����ʩչ" JIU "��\n");

        if (me->query_skill_mapped("unarmed") != "jiuyang-shengong")
                return notify_fail("������û�м���������Ϊȭ�ţ�����ʩչ" JIU "��\n");

        if (me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("������û�м���������Ϊ�ڹ�������ʩչ" JIU "��\n");



        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�����" JIU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���һ������ʱһ�ɺƵ��ޱȵ����������ڱŷ���˫��"
              "��Ȼ��������$n" HIR "�������ȥ��\n" NOR;

        ap = me->query_skill("force") + me->query("con") * 20;
        dp = target->query_skill("force") + target->query("con") * 20;

        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 9;
                msg += HIR "$n" HIR "ֻ����Χ���������ޱȣ��ּ�����������"
                       "�Լ�Ϯ�����ٸ�ͷ��Ŀѣ����֪����εֵ���\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "ֻ��$N" HIY "�����������Լ�Ϯ������"
                       "æǿ������ǿ�ֵ���\n" NOR;
                count = 0;
        }

        message_vision(msg, me, target);
        me->add_temp("apply/attack", count);

        me->add("neili", -300);

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) ==0 )
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(8));
        me->add_temp("apply/attack", -count);

        return 1;
}

