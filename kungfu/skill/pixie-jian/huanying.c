// huanying.c ��Ӱ

#include <ansi.h>

inherit F_SSERVER;


int perform(object me)
{
        
       string msg;
        
       object weapon, weapon2, target;
       
       int skill, ap, dp, damage;



       me->clean_up_enemy();
       
       target = me->select_opponent();


        skill = me->query_skill("pixie-jian",1);

   
       if( !(me->is_fighting() ))
            
       return notify_fail("����Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 
        if (!objectp(weapon = me->query_temp("weapon"))
        ||          (string)weapon->query("skill_type") != "sword")
          
        return notify_fail("��ʹ�õ��������ԡ�\n");

       
     if (!objectp(weapon2 = target->query_temp("weapon")))
                        return notify_fail("�Է�û���ñ������㲻��Ҫ�û�Ӱ��\n");

  
      if( skill < 100)
         
      return notify_fail("���Ƨа�����ȼ�����, ����ʹ�á���Ӱ����\n");

           if( me->query("neili") < 200 )
    
         return notify_fail("��������������޷����á���Ӱ����\n");

 
      if ((int)me->query_skill("kuihua-xinfa", 1) < 80 )
       
      return notify_fail(RED"������ķ���򲻹���ʹ��������Ӱ����\n"NOR);

        msg = HIC"$N��Ӱ���Σ�����΢�ڣ���$n�����ȥ\n"NOR;
              message_combatd(msg, me, target);

      
     damage = 10 + random(skill / 2)+600;
       
     ap = me->query_skill("sword") + skill;
       
      dp = target->query_skill("dodge")/2 ;
        
      if( dp < 1 )
          
      dp = 1;
    
      if( random(ap) > dp)
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = HIR"$nֻ��˫��һ���ʹ,���һ��������";
            msg += weapon2->name();
            msg += "��أ�һ������˳�ȥ��\n" NOR;
            me->start_busy(1);
            target->receive_damage("qi", damage);
            target->start_busy(2);  
            me->add("neili",-50);
    if (random(me->query("combat_exp"))> target->query("combat_exp")/2)
   {
            weapon2->move(environment(me));
   }
}            

    else
        {
                  
            me->add("neili",-50);
            msg = MAG"$n���������ֵ�����æ�����е�";

      msg += weapon2->name(); 

      msg += "����������$N����Ŀ,$Nֻ�����������\n"NOR;
            me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
