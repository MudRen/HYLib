// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hup.c ������Ԫ

#include <ansi.h>

#define HUP "��" HIR "������Ԫ" NOR "��"

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping my;
        int rp;
        int neili_cost;



        if ((int)me->query_skill("xiantian-qigong", 1) < 200)
                return notify_fail("�����칦�����������ʩչ" HUP "��\n");

        if ((int)me->query("max_neili") < 1000) 
                return notify_fail("���������Ϊ���㣬����ʩչ" HUP "��\n");

        if ((int)me->query("neili") < 200) 
                return notify_fail("�����ڵ���������������ʩչ" HUP "��\n");

        my = me->query_entire_dbase();
        if ((rp = (my["max_qi"] - my["eff_qi"])) < 1)
                return (SKILL_D("force") + "/recover")->exert(me, target);

        if (rp >= my["max_qi"] / 10)
                rp = my["max_qi"] / 10;

        skill = me->query_skill("force");
        msg = HIW "$N" HIW "�����³�һ��������ʱ����ͨ������ɫ�����ı�"
              "��ƽ�͡�\n" NOR;
        message_combatd(msg, me);

        neili_cost = rp + 100;
        if (neili_cost > my["neili"])
        {
                neili_cost = my["neili"];
                rp = neili_cost - 100;
        }
        me->receive_curing("qi", rp);
        me->receive_healing("qi", rp * 3 / 2);
        me->add("neili", -neili_cost);

        me->start_busy(3);
        return 1;
}
