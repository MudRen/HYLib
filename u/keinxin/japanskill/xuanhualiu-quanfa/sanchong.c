// ������ȭ��.���ؾ�sanchong

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill;

        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("���ؾ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("xuanhualiu-quanfa", 1) < 200 )
                return notify_fail("���������ȭ������������������ʹ�����ؾ���\n");

        if( me->query_temp("weapon") )
                return notify_fail("�������ֲ���ʹ�á����ؾ�����\n");

        if ( me->query_skill_mapped("unarmed") != "xuanhualiu-quanfa")
                return notify_fail("������Ƚ�������ȭ���������м�֮�в��С�\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 100)
		return notify_fail("��ı����ڹ���򲻹���\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������㣬ʹ������󡹦�ľ��У�\n");     

        if( (int)me->query_skill("cuff", 1) < 170 )
                return notify_fail("���ȭ��������죬ʹ������󡹦�ľ��У�\n");

        if( me->query_temp("sc_hama") )
                return notify_fail("���ʹ�꡸���ؾ������У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 80)
   return notify_fail("���ɱ���ķ���򲻹���\n");
        
        msg = HIW "\n$NͻȻȫ�����������һȭ������һ���ɫ��ȫ�������ʹ���������һ����\n   һȭ�����ȭ��ֱ��$n��ȥ��\n"NOR;        
        me->set_temp("sc_hama", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3
         || random(me->query("combat_exp")) > target->query("combat_exp")/2){                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("jing", -10);
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIG"�㵫��һ��ǿ�����������������������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("sc_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һȭ��ȴ�����Լ������������ˣ�\n");     

        msg = RED "\n�����ؾ�!��$N��ȭ����δ������ȭҲ���Ŵ����\n   ��$nû�в����ֿ���ʱ����ڶ���,ȭ����ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("shayi-xinfa", 1) > 199 ){                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -200);
                me->add("jing", -20);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(1);
                me->add("neili", -200);
                tell_object(target, HIG"�㴭Ϣδ�����ֿ�����δ������ֻ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("sc_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һȭ��ȴ�����Լ������������ˣ�\n");     

        msg = HIR "\n�����ؾ�!��$Nȫ�����һ����,ƴ����������ʹ����������ȭ�����ռ�������\n   $n��ͬ��ǰ��Բ����ȫ�ڡ����ؾ�!����������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("xuanhualiu-quanfa", 1) > 249 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIG"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/6, me);
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sc_hama");
        tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����ؾ��������ˡ�\n"NOR); 
}


