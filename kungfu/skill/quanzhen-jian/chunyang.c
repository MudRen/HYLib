// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count,damage,attack,dodge;
 	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʼʱ��������һ�ѽ���\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("qixing-array", 1) < 400 )
		return notify_fail("��ı����󷨲���!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("quanzhen-jian", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("xiantian-qigong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "xiantian-qigong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨȫ����ѧ��ʹ����ȫ��ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(5);
        msg = YEL "$Nʹ��ȫ���ɾ�����һ�������塹������Ȼ�ӿ�,���ս����γ�����������" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", (int)me->query_skill("quanzhen-jian",1)/3);

       msg = WHT  "��Ѫ������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "��Ѫ������" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT "ŭѪ������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIG "�������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "������λ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
        if (me->query_skill("qixing-array",1)>200)
{
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
        {
        message_vision(HIW"\n$N��������,Χ��$n��������Ȧ��$nֻ��һ���ۻ���\n"NOR,me,target);
//         msg = HIY "$N��������,Χ��$n��������Ȧ��$nֻ��һ���ۻ���" NOR;              
  if( !target->is_busy() )
{
         target->start_busy(2);
}
}

}

        me->add_temp("apply/attack", - (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", - (int)me->query_skill("quanzhen-jian",1)/3);
        msg = YEL "$Nʹ������������ǹ��¡�����̤������λ�������߸���Ӱ�����߸���λ��$n���������߽���\n"NOR;

        msg +=YEL "��һ�� \n" NOR;

	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;

                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
        } else 
        {
       
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

               
 
        msg += YEL "��һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
               
        } else 
        {

	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }
      

        msg += YEL "ǰһ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
        } else 
        {
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
         }  
	    msg += YEL "��һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
                
        } else 
        {
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

        msg += YEL "��һ�� \n" NOR;
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
               
        } else 
        {
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

	    msg += YEL "��һ�� \n" NOR;        
	
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

        if (random(attack) > dodge/2 )
        {

                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
                
        } else 
        {
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;
        }

           msg += YEL "���һ�� \n" NOR;
        
	    attack = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
	    dodge = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);                                      

        if (random(attack) > dodge/2 )
        {
                
                damage = (int)me->query_skill("quanzhen-jian",1);
                damage = damage* 3 + random(damage*6);
				damage = damage /4;
                                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);

	
                msg += RED"�͵�һ������Ӱ������$p��$Pһ�����أ��ҽ�һ���������˵��ϡ�\n" NOR;
	  } else 
        {
	
                msg += GRN"����$p������$P�����������μ���������׾ٵĶ������һ����\n" NOR;         
        }
        message_vision(msg, me, target);
 	msg = MAG "$Nһ����Х��һ�����н�����ʱ�γ�һ����Ļ����籩���ѹ��$n������
$n����֮�䣬��Ļ�зɳ��߶亮�ǣ������ǰ�����$n��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n������������Ȼ�н���\n";
		damage = 4*(int)me->query_skill("quanzhen-jian", 1);
		damage = damage / 2 + random(damage / 2);
		target->receive_wound("qi", damage/3);
	 	if( damage < 40 ) msg += HIY"$n���������������ϵ�����Ѫ��\n"NOR;
         	else if( damage < 80 ) msg += HIR"$n�����߽�����Ѫ���������\n"NOR;
         	else msg += RED"$n���ۡ��Ŀ��һ������������ߵ�Ѫ����\n"NOR;
		message_vision(msg, me, target);
	} 
	else {
	 	msg += HIW"$n�鼱֮����󼤷ɣ����ſ�£����������������һ����\n" NOR;
		message_vision(msg, me, target);
	}
        me->start_busy(4);

        return 1;
}

