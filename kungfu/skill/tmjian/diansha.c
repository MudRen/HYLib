
// diansha.c  ��ɱ
//��Ԫ,̴��,�羮,̫��,����,�ٻ�,����,ӿȪ,��׵
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int ap,dp,damage;
        object ob;
        string msg;
        string *order = ({"��ԪѨ", "̴��Ѩ", "�羮Ѩ", "̫��Ѩ", "����Ѩ", "�ٻ�Ѩ","����Ѩ","ӿȪѨ","��׵Ѩ"});
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(RED"����ɱ��ֻ����ս����ʹ�á�\n"NOR);

    if (me->query("family/family_name") != "�������" )
        return notify_fail("�㲻��������̵��ӣ�����ʹ�����������\n");
        
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
        return notify_fail("������û��װ������������\n");

        if ( (int)me->query_int() < 30 )
        return notify_fail("������첻�㣬����������ħ���ľ�����ʽ"RED"����ɱ����\n"NOR);

        if( (int)me->query_skill("tmjian",1)<199)
        return notify_fail("�����ħ����������죬���޷����"RED"����ɱ����\n"NOR);
                                
        if( (int)me->query_skill("tmdafa", 1)<70)
        return notify_fail("�����ħ�󷨹����������޷�ʹ��"RED"����ɱ����\n"NOR);

        if( (int)me->query("neili")<500)
        return notify_fail("����������̫��������ʹ��"RED"����ɱ����\n"NOR);

        if( (time()-(int)me->query_temp("last_perform_time"))<
                me->query_temp("last_perform_busy") )
                return notify_fail("���������ת��û����ô�졣\n");     

        me->set_temp("last_perform_time",time());
        me->set_temp("last_perform_busy",2);
        me->set_temp("last_perform_busy",4);

        msg=YEL"\n\nֻ��$N˫Ŀһ�ͣ���������һ����ʣ���ͻȻ�ӿ죬��Ӱ���Σ�������ϣ�\n"NOR;

        msg+=YEL"����һ�������ĳ�Х��$N���б���������佣�����͵�����$nȫ��������Ŵ�Ѩ��\n\n"NOR;

        me->add("neili",-random(500));

        ap=me->query_skill("tmjian")+me->query_skill("strike");
        dp=target->query_skill("parry")+target->query_skill("dodge");
        if(random(ap)+10>random(dp))   
           {
  target->start_busy(random(2));
                me->set_busy(1);
            damage=(me->query_str()-target->query_str()+10);
            damage=damage*random(me->query_cor());
/* */ damage=me->query("str")+me->query_skill("unarmed",1)/10;
/* */ damage=damage*(20+random(20))+800;

      if(damage<0)    damage=300;
      if(damage>6600) damage=6600;
      msg+=RED"$n����һ����"+HIY+(order[random(7)])+NOR+RED+"��λѪ���ɽ�,\n"NOR;
      switch(random(2))
      {
         case 1:
           {
               msg+=RED"$n���ۡ���һ����Ѫ�ӿ��������\n"NOR;
               target->reset_action();
 break;
           }
         default:
      msg+=RED"$n����һ��, һ����Ѫ�ӿ������,ֱ����$N,����$Nͷһ��,���ɵĶ��˹�ȥ����\n"NOR;
               target->reset_action();
      }
         switch(random(2))
     {
         case 1:
         { 
             target->receive_wound("qi",damage);
             target->receive_damage("qi",damage);
     if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage));
     break;
         }
      default:   
         { 
           target->receive_wound("qi",damage*2/3);
           target->receive_damage("qi",damage*5/4);
 if(wizardp(me)) tell_object(me,sprintf("damage: %d\n",damage*5/4));
                      }

                  }            
           }
        else 
           {
  me->start_busy(3);
                msg+=CYN"$p��Цһ����������μ������˿�ȥ��\n"NOR;
           }

        message_vision(msg, me, target);

        return 1;
}
