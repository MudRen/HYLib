// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// lei.c Ѹ��

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int j, z;
        object weapon;
        
        /*
        if (userp(me) && ! me->query("can_perform/xuantie-jian/lei"))
                return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ��Ѹ�ס���\n");
        */
                        
        j = me->query_skill("xuantie-sword", 1);
        z = me->query_skill("yunv-xinfa", 1);
 
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ѹ�ס�ֻ����ս���жԶ���ʹ�á�\n");

       if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ�ס���\n");
        if (me->query_skill_mapped("parry") != "xuantie-sword" && userp(me))
                return notify_fail("��Ļ����мܱ�������������ʱ����ʹ����Ѹ�ס���\n");
/*        || me->query_skill_mapped("sword") != "xuantie-sword"
               || me->query_skill_mapped("parry") != "xuantie-sword")
                return notify_fail("�������ʹ�ý�ʱ����ʹ����Ѹ�ס���\n");
*/

        if(me->query_skill("xuantie-sword", 1) < 160 )
                return notify_fail("�������������������죬ʹ������Ѹ�ס���\n");

        if(me->query_skill("yunv-xinfa", 1) < 160 )
                return notify_fail("���ŭ��������Ϊ������ʹ������Ѹ�ס���\n");

        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("����ڹ��ȼ�������ʹ������Ѹ�ס���\n");

        if( (int)me->query_str() < 32)
                return notify_fail("���������������ʹ������Ѹ�ס���\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("�������������ʹ������Ѹ�ס���\n");                                                                               

        if( (int)me->query("max_neili") < 1800 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n");      

        if( (int)me->query("neili") < 900 )
                return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 

        me->add_temp("apply/defense", z / 6);
        me->add_temp("apply/attack", j / 6); 
 
        msg = BLU "\n$N�����е�"+weapon->name()+"������$nһѹ����Ȼ����һ���� һ����Ϊ���������籼�׳��繥��$n��\n\n"NOR;
        message_combatd(msg, me, target);
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 

        me->add("neili", -500);
        
        me->add_temp("apply/defense", -z/6);
        me->add_temp("apply/attack", -j/6);

        me->start_busy(3);
        if( !target->is_busy() )
                target->start_busy(1);
        return 1;
}

