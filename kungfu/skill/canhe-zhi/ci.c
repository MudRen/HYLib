// ci.c canhe-zhi perform ���־�
// by leontt 1/5/2000
// modified by darken to reduce busy time

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
          return notify_fail("�����־���ֻ����ս���жԶ���ʹ�á�\n");
             
      if( objectp(me->query_temp("weapon")) )
          return notify_fail("��������ʹ�á����־�����\n");
          
      if( target->is_busy() )
          return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
      
      if( (int)me->query_skill("canhe-zhi",1) < 100 )
          return notify_fail("��Ĳκ�ָ������죬����ʹ�á����־�����\n");

      if( (int)me->query_skill("shenyuan-gong",1) < 100 )
          return notify_fail("�����Ԫ���ȼ�����������ʹ�á����־�����\n");  
      
      if( (int)me->query_str() < 30 )
          return notify_fail("��ı�������ǿ������ʹ�á����־�����\n");
      
      if( (int)me->query("max_neili") < 1000 )
          return notify_fail("�������̫��������ʹ�á����־�����\n");
      
      if( (int)me->query("neili") < 300 )
          return notify_fail("�������̫���ˣ��޷�ʹ�ó������־�����\n");   
                                                                                 
      if (me->query_skill_prepared("finger") != "canhe-zhi"
       || me->query_skill_mapped("finger") != "canhe-zhi")
          return notify_fail("�������޷�ʹ�á����־������й�����\n");                                                                                 
      
      if( me->query_temp("ci"))
          return notify_fail("������ʹ�òκ�ָ�����⹥�������־�����\n");
       
      msg = HIC"$NͻȻһ�������Լ��ĵ����ϼ���ȫ��������γ�һ�ɡ�"HIR"����"HIC"����������Ĵָ�������������$n�ļ粿��\n" NOR;
      message_vision(msg, me, target);   
//      me->start_perform(4,"�����־���");                                                                
      if(random(me->query("combat_exp"))>target->query("combat_exp")/4){
    
        msg = RED"$n�ļ�ؽ�һ�ᣬ˫����ʱʧȥ֪�����������á�\n"NOR;
      
        message_vision(msg, me, target); 
      
        improve = (int)me->query("dex");
        me->add_temp("apply/dexerity", improve);
        me->set_temp("ci",1);  
        me->add("neili", - 300);    
        target->start_busy(random((me->query_skill("douzhuan-xingyi",1)+me->query_skill("canhe-zhi",1))/60)+2);      
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :),
        me->query_skill("finger")/20+2);
      }
      else {
        msg = HIM"$n���ѿ�����$N����ͼ������һԾ�����ݵض����$N����һ�У�\n"NOR;          
        message_vision(msg, me, target);                                        
        me->start_busy(random(2)+1);                          
        me->add("neili", - 50);
      }
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dexerity", - improve);
      me->delete_temp("ci");
//    tell_object(me, HIR"�㡸���־�������, ����һ����ɫ������ࡣ\n"NOR);
}
