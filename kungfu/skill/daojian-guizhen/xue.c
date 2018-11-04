// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define XUE "��" HIW "������" HIR "Ѫ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        string type, msg;
        object weapon, weapon2;
        int i, count, damage;
        int ap, dp;

        if (me->query_skill("daojian-guizhen", 1) < 200)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
        if (! me->is_fighting(target))
                return notify_fail(XUE "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" XUE "��\n");

        type = weapon->query("skill_type");

        if (me->query_skill(type, 1) < 250)
                return notify_fail("���" + to_chinese(type) + "̫�"
                                   "����ʩչ" XUE "��\n");

        if (me->query_skill_mapped(type) != "daojian-guizhen")
                return notify_fail("��û�м����������棬����ʩչ" XUE "��\n");

        if (me->query_skill("daojian-guizhen", 1) < 250)
                return notify_fail("��Ľ�����ȼ�����������ʩչ" XUE "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" XUE "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "����" + weapon->name() + HIW "���һ��"
              "������" NOR + WHT "���ҵ���" HIW "������" NOR + WHT
              "��ҽ���" HIW "������ʩ������ʱ��\n���㣬����ҹ��"
              "���գ�����ǵ�����$n" HIW "������һ�С�" HIW "����"
              "��" HIR "Ѫ" HIW "����\n" NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("parry",1);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                msg += HIW "$n" HIW "ֻ���������⽣Ӱ���Լ���"
                       "�����ٸ��ۻ����ң��ĵ׺�����Ȼ������\n" NOR;
                count = ap / 15; 
                me->set_temp("daojian-guizhen/max_pfm", 1);
        } else
        {
                msg += HIG "$n" HIG "ͻȻ�����Լ����ܽԱ�����"
                       "��Ӱ����Χ����֪�����æС���мܡ�\n" NOR;
                count = ap / 30; 
        }
        message_combatd(msg, me, target);

        me->add("neili", -300);
        me->add_temp("apply/attack", count);
        me->add_temp("apply/damage", count * 2 / 3);

        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;
if (random(3)==0) target->start_busy(2);

                COMBAT_D->do_attack(me, target, weapon, 0);
        }
        me->add_temp("apply/attack", -count);
        me->add_temp("apply/damage", -count * 2 / 3);
        me->delete_temp("daojian-guizhen/max_pfm");
        me->start_busy(1 + random(8));
        return 1;
}
