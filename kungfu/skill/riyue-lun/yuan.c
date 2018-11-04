// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YUAN "��" HIY "Բ����" NOR "��"

inherit F_SSERVER;

//inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me)
{
        object weapon;
        string wp;
        int skill;



        if ((int)me->query_temp("yuan_man"))
                return notify_fail("����������ʩչ" YUAN "��\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" YUAN "��\n");

        if (me->query_skill_mapped("hammer") != "riyue-lun")
                return notify_fail("��û�м��������ַ�������ʩչ" YUAN "��\n");

        if (me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��û�м������������������ʩչ" YUAN "��\n");

        if ((int)me->query_skill("riyue-lun", 1) < 120)
                return notify_fail("��������ַ�����㣬����ʩչ" YUAN "��\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("����ڹ�����㣬����ʩչ" YUAN "��\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ���㣬����ʩչ" YUAN "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" YUAN "��\n");

        wp = weapon->name();

        message_combatd(HIY "$N" HIY "����������ʩ�������ַ���" HIW "Բ����"
                        HIY "��������" + wp + HIY "��ת��ɣ�Ѹ�ٻ�ס����Ҫ"
                        "����\n" NOR, me);

        skill = me->query_skill("riyue-lun", 1);
if (skill> 200) skill=200;
        me->add("neili", -200);
        me->add_temp("apply/defense", skill / 3);
        me->set_temp("yuan_man", 1);

        me->start_call_out((: call_other, __FILE__, "remove_effect",
                              me, skill / 3 :), skill / 2);

        if (me->is_fighting())
                me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        if ((int)me->query_temp("yuan_man"))
        {
                me->add_temp("apply/defense", -amount);
                me->delete_temp("yuan_man");
                tell_object(me, "���" YUAN "������ϣ��������ջص��\n");
        }
}


