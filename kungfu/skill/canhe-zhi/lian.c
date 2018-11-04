// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lian.c ����ָ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;


int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int skill,level;

                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("������ָ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_skill("canhe-zhi",1) < 200 )
                return notify_fail("��Ĳκ�ָ��򲻵����޷�ʩչĽ�ݼҴ���ѧ��\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 180)
                return notify_fail("�����Ԫ�����̫ǳ��\n");
        if ((int)me->query_skill("murong-daofa", 1) < 180)
                return notify_fail("���Ľ�ݵ������̫ǳ��\n");
        if ((int)me->query_skill("yanling-shenfa", 1) < 180)
                return notify_fail("������������̫ǳ��\n");
        if ((int)me->query_skill("xingyi-zhang", 1) < 180)
                return notify_fail("��Ķ�ת�����ƻ��̫ǳ��\n");
        if ((int)me->query_skill("murong-jianfa", 1) < 180)
                return notify_fail("���Ľ�ݽ������̫ǳ��\n");
        if ((int)me->query_skill("qxxy-shou", 1) < 180)
                return notify_fail("������������ֻ��̫ǳ��\n");
        if ((int)me->query_skill("canhe-zhi", 1) < 180)
                return notify_fail("��Ĳκ�ָ���̫ǳ��\n");
        if ((int)me->query_skill("douzhuan-xingyi", 1) < 180)
                return notify_fail("��Ķ�ת���ƻ��̫ǳ��\n");

        skill = me->query_skill("canhe-zhi", 1);

        if (skill < 80)
                return notify_fail("��Ĳκ�ָ��Ϊ����, ����ʹ�á�����ָ����\n");

        if (me->query("neili") < 70)
                return notify_fail("��������������޷����á�����ָ����\n");

        if (me->query_skill_mapped("finger") != "canhe-zhi")
                return notify_fail("��û�м����κ�ָ, ����ʹ�á�����ָ����\n");

        msg = HIC "$N" HIC "��ָ���������һ��ʢ������������ƮƮ�ķ���$n"
              HIC "��\n" NOR;

        me->add("neili", -30);
        ap = me->query_skill("finger");
        dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "���$p" HIR "��$P"
                       HIR "�Ƶ��мܲ�������Ͼ�Թˡ�\n" NOR;
                target->start_busy(random(4) + 2);
	} else
        {
		msg += CYN "����$p" CYN "������$P"
                       CYN "����ͼ������һԾ���㿪����һ�С�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

    msg = HIW "ֻ��$N" HIW "����һչ������Ȼ��ù����ޱȣ�������ָ��Ȼ��"
              "�������ɽ���ֱϮ$n" HIW "ҪѨ��ȥ��\n" NOR;  

        message_combatd(msg, me, target);

        me->start_busy(3);
        me->add("neili", -300);
        level = me->query_skill("canhe-zhi", 1);
        if (level>200) level=200;
        me->add("apply/attack", 80);
        msg = MAG "$Nһָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = YEL "$N��ָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = WHT "$N��ָ����$n�Ĵ��Ѩ"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg =RED "$N��ָ����$n���Ϲ�Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "$N��ָ����$n����ԨѨ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC "$N��ָ����$n���쾮Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIB "$N��ָ����$n�ļ�ȪѨ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = GRN "$N��ָ����$n������Ѩ" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        
        
        me->add("apply/attack", -80);

	return 1;
}

