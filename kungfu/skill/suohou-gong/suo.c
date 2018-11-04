// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define SUO "��" CYN "��צ����" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int ap, dp, damage,a,i,extra;
        string msg;
        string *limbs, limb;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(SUO "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("suohou-gong", 1) < 150)
                return notify_fail("��������򲻹�������ʩչ" SUO "��\n");

        if (me->query_skill_mapped("claw") != "suohou-gong")
                return notify_fail("��û�м�������������ʩչ" SUO "��\n");



        if ((int)me->query("neili", 1) < 500)
                return notify_fail("�����ڵ��������㣬����ʩչ" SUO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Ц����ذεض�������һ�С�" NOR +
              CYN "��צ����" HIR "��ֱȡ$n" HIR "������\n" NOR;
        me->add("neili", -20);

        ap = me->query_skill("claw");
        dp = target->query_skill("dodge");

        if (ap / 2 + random(ap) > dp)
        {
                damage = 0;

                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIR "��ʱֻ�������꡹һ�����죬$N" HIR "��"
                               "ָ����$n" HIR "�ĺ��������顣\n" NOR "("
                               " $n" RED "���˹��أ��Ѿ�������в�����ʱ"
                               "�����ܶ�����" NOR ")\n";

                        damage = -1;
                        me->start_busy(1);
                        me->add("neili", -50);

                } else
                {
                        target->start_busy(2);
        
                        damage = me->query_skill("claw");
                        
                        if (arrayp(limbs = target->query("limbs")))
                                limb = limbs[random(sizeof(limbs))];
                        else
                                limb = "Ҫ��";

target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);

                        msg +=HIR "$n" HIR "��æ������ȴ�������꡹һ"
                                                   "����$N" HIR "��ָ������$n" HIR "��" +
                                                   limb + "��\n" NOR;

                        me->start_busy(3);
                        me->add("neili", -180);
                }
        } else 
        {
                msg += CYN "����$n" CYN "������$P"
                       CYN "����ͼ�����μ������㿪����һץ��\n"NOR;
                me->start_busy(2);
                me->add("neili", -100);
        }
        message_combatd(msg, me, target);
extra=(int)me->query_skill("suohou-gong", 1)/20;
a=extra/2;
if (a> 12) a=12;
	for(i=0;i<a;i++)
	{
	msg = HIY  "$N����һ��������ʹ��һʽ������ʽ�������¶���ץ��$n��$l��" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", - 30);
	}
        //if (damage < 0)
                //target->die(me);

        return 1;
}

