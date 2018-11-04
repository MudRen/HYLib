// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hama.c ��󡹦

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p, ap, dp;
        string msg, dodge_skill;


                
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("��󡹦����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("hamagong", 1) < 100 )
                return notify_fail("��ĸ�󡹦����������������ʹ�ø����жԵУ�\n");

        if( me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�á���󡹦����\n");

        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("����ڹ����޴˹���\n");

        if (           me->query_skill_mapped("strike") != "hamagong")
                return notify_fail("������Ƚ���󡹦�������Ʒ�֮�в��С�\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query_skill("strike", 1) < 100 )
                return notify_fail("����Ʒ�������죬ʹ������󡹦�ľ��У�\n");

        if (me->query_str() < 30 )
                return notify_fail("�������̫С��ʹ�����ø����У�\n");


        if( me->query_temp("hmg_hama") )
                return notify_fail("���ʹ�꡸��󡹦�����У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

        
        msg = BLU "\n$N���Ӷ��£�����ƽ�ƶ�����ʹ������$N��ƽ�����ġ���󡹦�����У��Ʒ�ֱ��$n��ȥ��\n"NOR;        
        me->set_temp("hmg_hama", 1);
        
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("force") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)
	{                
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "����");
                call_out("perform2", 0, me, target, p);    
        } else 
        {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_combatd(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage, ap, dp;
        string msg, dodge_skill;

        if(! target || ! living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N���ƾ���δ��������Ҳ�����Ƴ����������������󡹦���Ʒ���ɽ������ӿ��$n��\n"NOR;   
             
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("dodge") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)   
	{     
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -300);           
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) 
                        damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "����");       
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(4);
                me->add("neili", -200);
                tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/4, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage, ap, dp;
        string msg, dodge_skill;
  
        if (! target) return 1;
        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N˫��һ�ǣ�˫���ಢ��ǰ�����Ƴ���$n��ͬ��ǰ��Բ����ȫ�ڡ���󡹦����������֮�£�\n"NOR;   
             
        ap = me->query_skill("force") * 3 / 2 + me->query("level") * 20 +  
             me->query_skill("martial-cognize", 1); 

        dp = target->query_skill("parry") + target->query("level") * 20 +
             target->query_skill("martial-cognize", 1); 

	if (ap / 2 + random(ap) > dp)  
        {
                me->start_busy(3);
                target->start_busy(random(2));
                me->add("neili", -400);          
                damage = (int)me->query_skill("hamagong", 1) * 2;     
                damage = damage + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                msg += COMBAT_D->damage_msg(damage, "����");
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jingli", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/3, me);
        message_combatd(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("hmg_hama");
        tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á���󡹦�������ˡ�\n"NOR); 
}


