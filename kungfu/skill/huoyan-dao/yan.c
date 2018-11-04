// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define YAN "��" HIR "�������" NOR "��"

inherit F_SSERVER; 
 
int perform(object me, object target)
{
        object weapon;
        string msg;


        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail(YAN "ֻ����ս���жԶ���ʹ�á�\n");
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʩչ" YAN "��\n");
         
        if (me->query_skill("force") < 200) 
                return notify_fail("����ڹ�����Ϊ�������޷�ʩչ" YAN "��\n");
        
        if (me->query_skill("huoyan-dao", 1) < 190) 
                return notify_fail("��Ļ��浶��Ϊ�������޷�ʩչ" YAN "��\n");
         
        if (me->query("neili") < 600 || me->query("max_neili") < 2000) 
                return notify_fail("��������������޷�ʩչ" YAN "��\n");

        if (me->query_skill_mapped("strike") != "huoyan-dao") 
                return notify_fail("��û�м������浶���޷�ʩչ" YAN "��\n");





        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ��ŭ�����������ע�뵥�ƣ���Ե��ʱ����һ�����ף��Ӷ�������$n"
              HIR "��ȥ��\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -300);

        me->add_temp("apply/attack", 50);
        msg = HIR "��һ������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        me->add_temp("apply/attack", 50);
        msg = HIR "�ڶ�������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", 50);
        msg = HIR "����������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack", 50);
        msg = HIR "���ĵ�����"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


        msg = HIR "���������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR "����������"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        // ������������
        me->add_temp("apply/attack", -200);

        me->start_busy(3);

        return 1;
}


