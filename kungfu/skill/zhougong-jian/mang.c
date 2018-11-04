// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define MANG "��" HIW "��â" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp, damage;
        object ob;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(MANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" MANG "��\n");

        if ((int)me->query_skill("zhougong-jian", 1) < 140)
                return notify_fail("����ܹ������̫ǳ������ʩչ" MANG "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���Ϊ̫ǳ������ʩչ" MANG "��\n");

        if ((int)me->query("max_neili", 1) < 2200)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" MANG "��\n");

        if ((int)me->query("neili", 1) < 500)
                return notify_fail("�����ڵ��������㣬������ʩչ" MANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");

        damage = me->query_skill("claw");

        msg = HIW "$N" HIW "һ����Х������" + weapon->name() + HIW "��"
                  "�ջ��������ⶸȻ����������²�������â��һ�������ƿ�"
                  "��ֱ����$n��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "һ���ҽУ������Ľ����ѻ�"
                                           "�����ţ������ϴ̳�����Ѫ������Ѫ��Ȫ"
                                           "ˮ��ӿ����\n" NOR;
        } else
        {
                msg += CYN "����$n" CYN "������$N"
                       CYN "����ͼ��бԾ�ܿ���\n" NOR;
        }

        msg += HIW "\n$N" HIW "��$n" HIW "Ӧ�Ӳ�Ͼ��һ����Ц�����л�����"
              "����һ�Ǹ��������Ľ�â�ɽ��ⵯ����������ֱ��$n" HIW
              "��\n" NOR;
        if (ap * 2 / 5 + random(ap) > dp)
        {
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "ֻ�������͡�һ������������$n" HIR
                                           "�ؿڣ�����һ����ڴ��Ѫ����$n" HIR
                                           "����һ������Ҳ�޷�վ��\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "ǿ��ȫ���ʹ��������һԾ���ܿ���$N"
                       CYN "��ǿ���ɱ�š�\n" NOR;
        }
        me->start_busy(2);
        me->add("neili", -400);
        message_combatd(msg, me, target);
        return 1;
}
