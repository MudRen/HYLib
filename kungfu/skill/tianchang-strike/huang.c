// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// huang.c �������

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        string msg;
        int skill, ap, dp, damage;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("��������ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon"))
                return notify_fail("������ֲ���ʩչ��������ġ���\n");

        if (me->query_skill_mapped("strike") != "tianchang-strike")
                return notify_fail("��û�м����쳥�Ʒ����޷�ʩչ��������ġ���\n");

        skill = me->query_skill("tianchang-strike", 1);

        if (skill < 100)
                return notify_fail("����쳥�Ʒ���Ϊ���ޣ�����ʹ�á�������ġ���\n");

        if (me->query("neili") < 150)
                return notify_fail("��������������޷����á�������ġ���\n");

        if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "���롱��һ����ȣ�����������ֻ������һƬѪ�죬ٿ������ĳ���"
              HIR "һ���ȷ��ʱϮ��$n" HIR "����ǰ��Ѩ��\n" NOR;

        ap = me->query_skill("strike",1);
        dp = target->query_skill("parry",1);
             
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -120);
                me->start_busy(2);
                damage = me->query_skill("strike",1)*2;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "һʱ��ֻ������Ѫ��ӿ����"
                                           "�������٣���Ϣ���ң����ɵ�����һ��"
                                           "��Ѫ��\n" NOR;

        } else
        {
                me->add("neili",-50);
                msg += HIC "Ȼ��$n" HIC "�ڹ���տ��˿����Ϊ$N"
                       HIC "���Ʒ���������������" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
