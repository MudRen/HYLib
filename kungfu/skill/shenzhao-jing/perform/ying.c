// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YING "��" HIR "��Ӱ��ȭ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl;

        if (! target) target = offensive_target(me);



        if (! target || ! me->is_fighting(target))
                return notify_fail(YING "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(me->query_temp("weapon")))
                return notify_fail("�������ֲ���ʩչ" YING "��\n");

        if (me->query_skill_mapped("unarmed") != "shenzhao-jing")
                return notify_fail("��û�м������վ���Ϊ���ּ��ܣ��޷�ʩչ" YING "��\n");



        if ((int)me->query_skill("shenzhao-jing", 1) < 200)
                return notify_fail("������վ��񹦻�򲻹����޷�ʩչ" YING "��\n");

        if ((int)me->query_skill("unarmed", 1) < 200)
                return notify_fail("��Ļ���ȭ�Ż�򲻹����޷�ʩչ" YING "��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ" YING "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʩչ" YING "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "ٿȻԾ����������Ӱ����һȭ��ȥ�ƿ켫��ȭӰ��"
              "�ص�����ֱϮ$n" HIR "��ȥ��\n"NOR;

        lvl = me->query_skill("shenzhao-jing", 1);

        ap = me->query_skill("force")  + me->query("con") * 10;
        dp = target->query_skill("force")   + target->query("con") * 10; 

        me->start_busy(4);
        if (ap * 11 / 20 + random(ap) > dp)
        { 
                damage = me->query_skill("force");
                me->add("neili", -400);
                target->apply_condition("shenzhao",lvl/2);
       target->add("qi",-damage+500);
		target->add("eff_qi",-damage+500);
                msg += HIR "$n" HIR "��ȭ�Ʊ任Ī�⣬ֻ��"
                               "΢΢һ㶣��ѱ�$N" HIR "һȭ�����ؿڣ����վ���"
                               "����\nʱ����ɽ�鱬��һ�㣬͸����롣\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "��$N" CYN "������ӿ����æ����Ծ����\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}

