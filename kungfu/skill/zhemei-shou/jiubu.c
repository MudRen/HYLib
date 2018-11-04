// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiubu.c �Ų�ʽ

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
		return notify_fail("���Ų�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if (userp(me) && ! me->query("can_perform/zhemei-shou/jiubu"))
//                return notify_fail("�㻹û������������о������޷�ʩչ���Ų�ʽ����\n");
                
	if ((int)me->query_skill("zhemei-shou", 1) < 120)
		return notify_fail("�����÷�ַ�������죬����ʹ�á��Ų�ʽ����\n");
	                        
	if ((int)me->query_skill("force") < 200)
		return notify_fail("����ڹ���Ϊ�����ߣ��������á��Ų�ʽ����\n");
			
	if ((int)me->query("neili") < 100)
		return notify_fail("��������������������ʹ�á��Ų�ʽ����\n");

        if (me->query_skill_mapped("hand") != "zhemei-shou")
                return notify_fail("��û�м�����ɽ��÷�֣�����ʹ�á��Ų�ʽ����\n");

	msg = HIC "$N" HIC "˫������ʵʵ��ץ��$n"
              HIC "��Ҫ��������翣���ʽ���أ���������׽����\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("hand");
		me->add("neili", -100);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "һ�����ܲ����������$P"
                                           HIR "ץ�˸����У�������Ϣ���ɵ�һ�ͣ���Ѫ��ӿ��\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "����$p" HIC "�������ݣ�����Ķ����$P"
                       HIC "�Ĺ�����\n"NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
