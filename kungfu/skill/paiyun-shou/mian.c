// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// mian ���಻��


#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,x;
        int i,j,k,y;


                        
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("�����಻����ֻ����ս���жԶ���ʹ�á�\n");
                
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á����಻����ʱ������֣�\n");
                
        if( (int)me->query_skill("paiyun-shou", 1) < 120 )
                return notify_fail("����������ֲ�����죬����ʹ�á����಻������\n");
                
        if( (int)me->query("max_neili") < 1100 )
                return notify_fail("������������Ϊ����������ʹ�á����಻������\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�á����಻������\n");
                
        if( me->query_skill_prepared("hand") != "paiyun-shou"
        ||  me->query_skill_mapped("hand") != "paiyun-shou")
                return notify_fail("�����ȫ�������������֣�����ʹ�á����಻������\n");

                
        i = (me->query_skill("paiyun-shou", 1)/5);
        //if( target->is_busy() ) i*=2;
        if( (int)me->query_skill("paiyun-shou", 1) > 280 )
        {
                y = 7;
        } else 
        if( (int)me->query_skill("paiyun-shou", 1) > 180 )
        {
                y = 5;
        } else 
        if( (int)me->query_skill("paiyun-shou", 1) > 140 )
        {
                y = 4;      
        }
        else 
        {
                y = 3;
        }
        msg = HIY "$N��Ȼ��������˫��Ȧ���������ʵ��������ա�һ���ĳ����ڶ��ƽ��������һ��"+chinese_number(y)+"�ƣ����������ƹ�����\n" NOR;
        message_combatd(msg, me, target);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
        for(k = 0; k < y; k++)
        {
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -i);
        me->add("neili", -400);
        me->start_busy(2);
        return 1;
}

