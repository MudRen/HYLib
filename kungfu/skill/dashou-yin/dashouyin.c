// dashouyin dashou-yin perform
// by dubei

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

int perform(object me, object target)
{
      string msg, dodge_skill;                                
      int damage, jiali, attack, defense, p;
      object armor;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target) )
           return notify_fail("������ӡ��ֻ����ս���жԶ���ʹ�á�\n");        
      
      if( (int)me->query_skill("dashou-yin",1) < 120 )
           return notify_fail("��Ĵ���ӡ������죬����ʹ�������񹦡�����ӡ����\n");
      
      if( (int)me->query_skill("hand",1) < 120 )
           return notify_fail("��Ļ����ַ�������죬����ʹ�������񹦡�����ӡ����\n");

      if( (int)me->query_skill("longxiang",1) < 120 )
           return notify_fail("�������������ȼ�����������ʹ�á�����ӡ����\n");  
      
      if( (int)me->query_str() < 35 )
           return notify_fail("��ı�������ǿ������ʹ�á�����ӡ����\n");
      
      if( (int)me->query("max_neili") < 1000 )
           return notify_fail("�������̫��������ʹ�á�����ӡ����\n");
      
      if( (int)me->query("neili") < 800 )
           return notify_fail("�������̫���ˣ��޷�ʹ�ó�������ӡ����\n");   
       
      if( (int)target->query_condition("dashouyin"))
           return notify_fail("�Է��������С�����ӡ�������ˣ�\n");   
      
      if ( me->query_skill_mapped("hand") != "dashou-yin"
        || me->query_skill_mapped("parry") != "dashou-yin")
           return notify_fail("�������޷�ʹ�á�����ӡ����\n");   
          
      if( objectp(me->query_temp("weapon")) )
           return notify_fail("��������ʹ�á�����ӡ����\n");                                                                              
      
       
      jiali = me->query("jiali")+1;
      attack = me->query("combat_exp")/1000;
      attack += me->query_skill("hand");
      attack += me->query("neili")/5;
      defense = target->query("combat_exp")/1000;
      defense += target->query_skill("dodge");
      defense += target->query("neili")/7;
      attack = (attack+random(attack+1))/2;
      
      damage = me->query_skill("dashou-yin", 1)/40 * jiali;
      if(damage > 1500) damage = 1500;
      
      message_vision(BLU"\n$NͻȻ��ɫ���죬����Ĭ���������ԣ�˫�۹ǽ�һ���죬��Ȼ�ڿն���������$n��ǰ��ȥ����һʽ���ڡ�����ӡ����\n"NOR,me,target);
 
      if( attack > defense ) { 
      	 if( objectp(armor = target->query_temp("armor/cloth"))
      	    && armor->query("armor_prop/armor") < 1500
      	    && damage > 500){
                	message_vision(HIY"ֻ���⶷�����ӡ����ӡ��$N��$n"HIY"�ϣ�Խ��Խ�󣬾�������÷��飬�ѳ�һ�����ڵ��ϣ�\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "�����" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
                        }
      	 tell_object(target, RED"��ֻ���û����ؿ�һ���ʹ���Ѿ���������ǰ�أ�\n"NOR);
      	 target->apply_condition("dashouyin", 1+(me->query_str()/8));
      	 target->receive_damage("qi", damage,  me); 
         target->receive_wound("qi", damage, me);
         p = (int)target->query("qi")*100/(int)target->query("max_qi");
         msg = damage_msg(damage, "����");
         msg += "( $n"+eff_status_msg(p)+" )\n";
         message_vision(msg, me, target);
         me->add("neili", -jiali);
      	}
      else {
      	 dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
         }
      me->add("neili", -200);
      me->start_busy(2);            
      return 1;
}

 
