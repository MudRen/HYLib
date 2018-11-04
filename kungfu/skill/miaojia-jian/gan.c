// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define GAN "��" HIY "���Ǹ���" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, wn;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(GAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" GAN "��\n");

        if ((int)me->query_skill("miaojia-jian", 1) < 200)
                return notify_fail("����ҽ���������죬����ʩչ" GAN "��\n");

        if ((int)me->query_skill("force") < 280 )
                return notify_fail("����ڹ���򲻹�������ʩչ" GAN "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ����������ʩչ" GAN "��\n");

        if ((int)me->query("neili") < 600)
                return notify_fail("��������������������ʩչ" GAN "��\n");

        if (me->query_skill_mapped("sword") != "miaojia-jian")
                return notify_fail("��û�м�����ҽ���������ʩչ" GAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIY "$N" HIY "��������������" + wn + HIY "�ų�����⻪����Ȼ���ƿ�"
              "�����죬" + wn + HIY "��������������ǰ���$n" HIY "��ȥ��\n" NOR;
        ap = me->query_skill("sword",1);
        dp = target->query_skill("parry",1);

        if (ap / 2 + random(ap) > dp)
        {
                me->start_busy(3);
                damage = me->query_skill("sword",1)*3;
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "��ʱ��ʧɫ��ֻ���ؿڴ�"
                                           "һ�����Ǳ�" + wn + HIR "��Ȼ�Ѿ�����͸"
                                           "��������һ��Ѫ�꣡\n" NOR;


                me->add("neili", -500);
        } else
        {
                me->start_busy(4);
                msg += HIC "$n" HIC "��" + wn + HIC "������ӿ����֪��"
                       "���ɵ����������������ߣ����ڶ���������\n" NOR;
                me->add("neili", -500);
        }

        if (userp(me) && (int)me->query_skill("miaojia-jian", 1) < 60)
        {
                msg += HIY "ֻ��" + wn + HIY "���Ʋ���������ǰ�ɳ���"
                       "�ɣ�����û�����С�\n" NOR;
                weapon->move(environment(me));
        } else
                msg += HIY "Ȼ��$N" HIY "����һչ����ʱԾ�����ɣ���"
                       "����磬�������" + wn + HIY "�ֳ������С�\n" NOR;

        message_combatd(msg, me, target);
        return 1;
}
