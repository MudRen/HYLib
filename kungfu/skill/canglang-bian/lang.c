// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
      
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
  

int perform(object me, object target) 
{ 
        object weapon; 
        int skill; 
        
        if (! target) target = offensive_target(me); 

        if (! target 
        ||      ! target->is_character() 
        ||      ! me->is_fighting(target)) 
                return notify_fail("���������졹ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if (! objectp(weapon = me->query_temp("weapon"))  
        ||      (string)weapon->query("skill_type") != "whip")  
                return notify_fail("��û�б����֣�ʩ�������������졹��\n");  

        if ((int)me->query("neili") < 200)  
                return notify_fail("�������������\n");  

        if (me->query_skill("canglang-bian", 1) < 50)  
                return notify_fail("��ġ����˱޷� ��δ�����磬�޷�ʩ�����������졹��\n");  

        if (me->query_skill("bibo-shengong", 1) < 50)  
                return notify_fail("��ı���������Ϊ�������޷�ʩ�������˱޷�����\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("�����õĲ��ǡ����˱޷� ����ʩչ�������������졹��\n");  

        if (me->query_temp("julang") )  
                return notify_fail("���Ѿ�����ʩչ���������졹�ˣ�\n");  

        message_combatd(
                HIR "$N��Ȼ��" + (me->query_temp("weapon"))->query("name") + 
                HIR "ƵƵ˦����" + (me->query_temp("weapon"))->query("name") + 
                HIR "������ž����֮�������ŵ�$n�ķ����ҡ�\n" NOR, me, target);   
        message_combatd(
                HIB "$N��������ǧ������ͷȴ����ָ��$n������ҪѨ��������������������޾���"
                "��$nֻ���м�֮��ȴ�޻���֮����\n" NOR, me, target); 

        me->set_temp("julang", 1); 

        skill =  ( me->query_skill("canglang-bian") + me->query_skill("dodge") ) / 4; 

        me->add_temp("apply/attack", 100); 
        me->add_temp("apply/defense",  100); 

        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add("neili", -200); 
        me->start_busy(random(2)); 

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/5); 

        return 1; 
} 
      
private int remove_effect(object me, int amount) 
{ 
        if ((int)me->query_temp("julang"))
        {
                me->add_temp("apply/attack", -100); 
                me->add_temp("apply/defense", -100); 
                me->delete_temp("julang"); 
                message_combatd(YEL "\n$N���������ڹ���������ѹ�£�\n\n" NOR, me);
        }

        return 0; 
} 
