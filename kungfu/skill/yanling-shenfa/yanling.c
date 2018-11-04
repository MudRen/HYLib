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
      return notify_fail("���鶯���ࡹֻ����ս����ʹ�á�\n");
             
      
      if( (int)me->query_skill("yanling-shenfa",1) < 120 )
                return notify_fail("���������������죬����ʹ�á��鶯���ࡹ��\n");

      if( (int)me->query_dex() < 20 )
                return notify_fail("�����̫�ͣ�����ʹ�á��鶯���ࡹ��\n");

      if (me->query_skill("shenyuan-gong", 1)<50)
                return notify_fail("��ı����ڹ����δ������\n");

      
      if( (int)me->query_skill("dodge",1) < 150 )
                return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á��鶯���ࡹ��\n");
      
      if( (int)me->query("neili") < 400 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó����鶯���ࡹ��\n");   
    
      if (me->query_skill_mapped("dodge") != "yanling-shenfa")
               return notify_fail("�����ڼ�����������ʹ�á��鶯���ࡹ������\n");                                                                                 
      if( me->query_temp("yanling")   )
      return notify_fail("������ʹ��������������������鶯���ࡹ��\n");
       
     msg = HIG"$NͻȻ����һ������ͻȻ֮��θ����ɣ����Ƹվ�������һ������" +
               "��������������������һֻ�鶯�����ӣ�\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->set_temp("yanling",1);  
      me->add("neili", -(350-(int)me->query_skill("yanling-shenfa",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("yanling-shenfa") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->delete_temp("yanling");
      tell_object(me, HIR"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
      tell_room(environment(me), HIW + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n" NOR,  ({ me }));
    
}
