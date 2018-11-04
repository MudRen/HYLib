// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define ZHEN "��" HIW "�桤������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int ap, dp;
        int i, count,damage;
        string msg;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(ZHEN "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("longxiang", 1) < 370)
                return notify_fail("��������������Ϊ����������ʩչ" ZHEN "��\n");

        if (me->query("max_neili") < 7000)
                return notify_fail("���������Ϊ���㣬����ʩչ" ZHEN "��\n");

        if (me->query_skill_mapped("unarmed") != "longxiang")
                return notify_fail("��û�м������������Ϊȭ�ţ�����ʩչ" ZHEN "��\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��û�м������������Ϊ�ڹ�������ʩչ" ZHEN "��\n");



        if (me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" ZHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "����һ��ŭ������������������������ޣ�ȫ���ʱ�"
              "�ŷ����������ڶ���������$N" HIY "\n�ķ�������ʯ�䣬$N" HIY "˫"
              "ȭ��Я���������֮�Ʊ����������������ﳾ�����������ھ�ѧ��\n\n" NOR;

        msg += HIW
        "        ��      ����           ��        ��           ��    ������������\n"
        "    �����    ��  ��       ��������������������       ��       ��    ��\n"
        "    ��    ��    ��  ��           ��        ��       ����������  ��    ��\n"
        "    �� �� �� ���    ���          ��                 ������  ������ ������\n"
        "  �������             ������������������������  �� �� ��  ����     ��\n"
        "    ��    ��   �����         ��                   �� �� ��  �� ��   ��\n"
        "    �� �� ��    ��  ��        �� ��������������      �� �� �� ��   ����\n"
        "    ��    ��     ���       ��   ��          ��         ��   ��     ��\n"
        "   ��    ��   ���  ���         ��������������         ��  ��  ����������\n\n" NOR;

        msg += HIY "$N" HIY "һ��������������ű�ӿ���˵ڶ���������������������"
               "���಻����������磡ֱ��$N" HIY "\n��ʮ�����������꣬����������"
               "�ŵ�������������ˣ���$n" HIY "��ʱȴ���Ǳ��޿ɱܣ�\n\n" NOR;

        ap =  me->query_skill("unarmed")+ me->query("con") * 20;
        dp =  target->query_skill("parry") + target->query("dex") * 20;

        if (me->query("max_neili") / 2 + random(me->query("max_neili") / 2) > target->query("max_neili"))
        {
                msg += HIR "$n" HIR "ȫȻ�����赲������$N"
                       HIR "һȭ���÷������صĵ����ڵ��ϡ�\n" NOR;
                me->add("neili", -50);
                me->start_busy(1);

                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
		
                message_combatd(msg, me, target);

                target->receive_damage("qi", damage); 
                if (userp(target) && random(3)==0)
                {
                target->unconcious(me);
              }
              else
              	{
              	target->start_busy(10);
              	}
                return 1;
        } else
        if (ap * 3 / 2 + random(ap) > dp)
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

        message_combatd(msg, me, target);
        me->add_temp("apply/attack", count);
if (count>=200) count=200;
        me->add("neili", -300);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(3) == 0 && ! target->is_busy())
                        target->start_busy(3);

                COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->start_busy(1 + random(5));
        me->add_temp("apply/attack", -count);

        return 1;
}

