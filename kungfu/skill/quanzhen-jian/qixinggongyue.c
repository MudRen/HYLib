// qixinggongyue.c �����---���ǹ���

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me,object target)
{
        int damage,attack,dodge;
        string msg;
        object ob;
        if( !target ) target = offensive_target(me);

	 if( !target
      	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ǹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


         if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�����ʹ�����ǹ��¡�\n");        
                
        if( (int)me->query_skill("quanzhen-jian",1) < 280 )
                return notify_fail("���ȫ�潣���������ң��޷�ʹ�á����ǹ��¡���\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 280 )
                return notify_fail("��������񹦻�򲻹����޷�ʹ�á����ǹ��¡���\n");
                        
        if( (int)me->query_skill("qixing-array",1) < 200 )
                return notify_fail("��ı����������ܱ��򲻹����޷�ʹ�á����ǹ��¡���\n");

    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("��Ҫ����������Ϊ�ڹ������á�\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("����������̫��������ʹ�����ǹ��¡�\n");
                        
        if( (int)me->query("jing") < 80 )
                return notify_fail("��ľ����㣬����ʹ�����ǹ��¡�\n");

        msg = YEL "$Nʹ������������ǹ��¡�����̤������λ�������߸���Ӱ�����߸���λ��$n���������߽���\n"NOR;

        msg +=YEL "��һ�� \n" NOR;

	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
       
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

               
 
        msg += YEL "��һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
               
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }
      

        msg += YEL "ǰһ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
         }  
	    msg += YEL "��һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
                
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

        msg += YEL "��һ�� \n" NOR;
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
               
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

	    msg += YEL "��һ�� \n" NOR;        
	
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
                
        } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

           msg += YEL "���һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);                                      

        if (random(attack) > dodge/2 )
        {
                me->start_busy(2);
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 2 + random(damage*6);
				damage = damage /3;
				if(wizardp(me)) printf("damage = %d\n",damage); 
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                me->add("neili", -150);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
	  } else 
        {
                me->start_busy(2);
                me->add("neili",-150);
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;         
        }
        message_vision(msg, me, target);

        return 1;
}



