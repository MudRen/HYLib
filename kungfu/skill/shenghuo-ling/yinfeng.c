// yinfeng.c ���絶
// by snowman

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{        
           object weapon;
// mapping fam
        int damage, p;
        string msg;
        weapon = me->query_temp("weapon");

        if( !target) target = offensive_target(me);
        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("�����絶��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
       
//        if (me->query_skill_mapped("sword") != "shenghuo-lingfa")
//                return notify_fail("������Ƚ�ʥ�������ʥ�����໥��ϡ�\n");
        if(!weapon)
                return notify_fail("�����ʹ���������������絶�ھ���\n");   
//        if(!(weapon->id("shenghuo ling") || weapon->id("tieyan ling") || weapon->id("tie ling")))
//                return notify_fail("�����ʹ��ʥ��������������������絶�ھ���\n");     
        if( (int)me->query_skill("shenghuo-shengong",1) < 130 )
                return notify_fail("���ʥ���񹦵ȼ�����������ʩչ���絶�ھ���\n");
        if( (int)me->query_skill("shenghuo-ling",1) < 130 )
                return notify_fail("���ʥ����ȼ�����������ʩչ���絶�ھ���\n");
        if( (int)me->query_skill("force", 1) < 130 )
                return notify_fail("��Ļ����ڹ��ȼ�����������ʩչ���絶�ھ���\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("����������㣬����ʩչ���絶�ھ���\n");
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("����������㣬����ʩչ���絶�ھ���\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("��ľ������㣬����ʩչ���絶�ھ���\n");

        tell_object(me, HIW"\n������ʹ��"BLU"���絶"HIW"������һ���������ʵ�����֮����ֱ��"+target->name()+"�ؿ�����ѨҪѨ��\n"NOR); 
      if(random(me->query_skill("force"))*(me->query_temp("yinfeng")+1) > 
         random(target->query_skill("force")/3)){                
           damage = me->query_skill("force");
           damage = damage + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force")/2)
             damage = damage/2;                  
           if(target->query_skill("force") > me->query_skill("force"))
             damage = random(50);
           if(me->query_skill("force") > target->query_skill("force"))
             damage = damage+random(damage);
           if(me->query_temp("yinfeng"))
             damage = damage*(me->query_temp("yinfeng")+1);
           if(damage > 1000){
              tell_object(target, HIB"\nͻȻ֮�䣬һ���������ʡ�������е�����֮��ֱ�������ؿڵġ�����Ѩ���У�
"HIR"����ʱ֮�������Ϣ��ȫ�������ã�\n"NOR);
              target->start_busy(3);
              }
           else if(damage <= 50){
              damage = 10;
              tell_object(target, HIY"\nͻȻ֮�䣬һ��������а������֮��ֱ�����ؿڵ�����Ѩ��
�Һ��㻤���񹦱黤ȫ��������絶������ȴҲ���㲻�ã�\n"NOR);
              tell_object(me, HIY"���������絶���ھ��������Է����Ǻ��������ĵֵ���������\n"NOR);
              }
           else{
              tell_object(target, HIB"\nͻȻ֮�䣬һ�������絶���罣����ذ�����䣬ֱ�������ؿڵġ�����Ѩ���У�
"HIR"����ʱ֮�������Ϣ��ȫ�������ã�\n"NOR);
              target->start_busy(2);
              }
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           target->add("neili", -damage/2); 
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"ͻȻȫ���͵�һ�������ֽ���������������ݷ�ʲô�����ؿڴ��ͻ���һ���Ƶģ�\n" NOR, ({ target })); 
           msg = damage_msg(damage, "����");
           msg += "( $n"+eff_status_msg(p)+" )\n"; 
           message_vision(msg, me, target);          
//           if(!target->is_killing(me->query("id"))) target->kill_ob(me);      
           me->start_busy(2);
           me->add("neili", -200);
           return 1;
           }
         
     else {       
          me->add("neili", -100);
           me->start_busy(2);
          tell_object(me, HIY"������絶�ھ���û����"+target->name()+"��������Ѿ�ɢ�ˡ�\n"NOR);
          }
        return 1;
}
