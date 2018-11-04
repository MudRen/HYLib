// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// po.c ���־�

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;


                
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("���á����־������б����е���\n");

	if ((int)me->query_skill("hujia-daofa", 1) < 90)
		return notify_fail("��ĺ��ҵ���������죬����ʹ�á����־�����\n");
	                        
	if ((int)me->query_skill("force") < 150)
		return notify_fail("����ڹ���Ϊ�����ߡ�\n");
			
	if( (int)me->query("neili") < 300 )
		return notify_fail("����������̫��������ʹ�á����־�����\n");
			
	msg = HIM "$N" HIM "���е�" + weapon->name() +
              HIM "����һת��һ�����ε�����Ȼ��Ϣ��Ϯ��$n" HIM "��\n"NOR;

        ap = me->query_skill("blade",1);
        dp = target->query_skill("force",1);
             
        if (ap / 2 + random(ap) > dp)
	{
		damage =  me->query_skill("blade",1);
                me->add("neili", -150);
                		target->add("qi",-damage);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                     HIR "ֻ��$n" HIR "һ���ҽУ�����������"
                                           "�����������Ѫ���������\n" NOR;
                

		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "Ĭ��������Ӳ�ǵֵ���$P"
                       HIC "��������ε�����\n"NOR;
                me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
