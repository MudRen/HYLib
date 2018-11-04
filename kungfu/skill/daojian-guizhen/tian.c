// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define TIAN "��" HIR "����������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        string type1, type2, msg;
        object weapon1, weapon;
        int ap, dp, damage;

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
                return notify_fail(TIAN "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword"
           && (string)weapon->query("skill_type") != "blade" )
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" TIAN "��\n");




        if (me->query_skill_mapped("sword") != "daojian-guizhen"
           || me->query_skill_mapped("blade") != "daojian-guizhen")
                return notify_fail("��û�м����������棬����ʩչ" TIAN "��\n");

        if (me->query_skill("daojian-guizhen", 1) < 250)
                return notify_fail("��Ľ�����ȼ�����������ʩչ" TIAN "��\n");

        if (me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        ap = me->query_skill("sword") +
             me->query_skill("blade") +
             me->query_skill("daojian-guizhen", 1) * 3 / 2;

        dp = target->query_skill("force") +
             target->query_skill("dodge") +
             target->query_skill("parry", 1);

        damage = me->query_skill("sword",1)+me->query_skill("blade",1);

        msg = HIY "$N" HIY "��" + weapon->name() + HIY "��" +
              weapon->name() + HIY "��������ǰ����ת����"
              HIR "����������" HIY "���������ھ��纣Х�㱬����\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {
                msg += HIR "$n" HIR "��$N" HIR "ɱ�����ǣ�������"
                       "�����⣬�мܶ�ʱɢ�ң�ȫȻ��������\n" NOR;
                ap += ap / 5;
                damage += damage / 3;
        } else
        {
                msg += HIG "$n" HIG "��$N" HIG "ɱ�����ǣ�˿����"
                       "�Ҵ��⣬��æ��������Ŭ�����ܸ��š�\n" NOR;
        }

        msg += HIW "\nͻȻ��$N" HIW "����һչ������" + weapon->name() +
               HIW "����һ����վ��һ���뻡��ֱ��$n" HIW "��ȥ��\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {
        	
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "�����ֵ���ȴ�����мܵ�ס"
                                           "����$N" HIR "һ�л���Ҫ������Ѫ�Ĵ���"
                                           "����\n" NOR;
        	

        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }

        msg += HIW "\n����$N" HIW "�ֽ�����" + weapon->name() +
               HIW "��$n" HIW "ƽƽ�ݳ�����ʽ���Ƽ򵥣�ȴ�̲���"
               "�����ɱ�š�\n" NOR;

        if (ap * 2 / 3 + random(ap) > dp)
        {
                // ת������
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "$n" HIR "ֻ���ۻ����ң�ȫȻ�޷���"
                                           "���Ȼ���$N" HIR "һ�����У����һ����"
                                           "Ѫ��\n" NOR;
                // ת�ƻس�ʼ״̬

        } else
        {
                msg += CYN "$n" CYN "��֪��һ�е���������æ����"
                       "������С�Ĳ��У�˿������\n" NOR;
        }
        me->start_busy(3);
        me->add("neili", -300);
        message_combatd(msg, me, target);
        return 1;
}
