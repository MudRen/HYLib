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
      return notify_fail("�������ݡ�ֻ����ս����ʹ�á�\n");
             
      
      if( (int)me->query_skill("tiyunzong",1) < 120 )
                return notify_fail("��������ݲ�����죬����ʹ�á������ݡ���\n");
      
      if( (int)me->query_skill("taiji-shengong",1) < 120 )
                return notify_fail("��������ȼ�����������ʹ�á������ݡ���\n");  
      if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("����ڹ����ԣ�����ʹ�á������ݡ���\n");
      if( (int)me->query_dex() < 20 )
                return notify_fail("�����̫�ͣ�����ʹ�á������ݡ���\n");
      
      if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("��Ļ����Ṧ̫����屿׾������ʹ�á������ݡ���\n");
      
      if( (int)me->query("neili") < 400 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó��������ݡ���\n");   
    
        if (me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("�����ڼ�����������ʹ�á������ݡ�������\n");                                                                                 
      if( me->query_temp("zong")   )
      return notify_fail("������ʹ�������ݵ���������������ݡ���\n");
       
     msg = HIW"$NͻȻ����һ������һ̧���͵İθ����ɣ����Ƹվ���˫�������߳���" +
               "�������������������������������£�\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->set_temp("zong",1);  
      me->add("neili", -(350-(int)me->query_skill("tiyunzong",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("tiyunzong") * 2/3 );
//    me->start_perform(me->query_skill("tiyunzong")/3, "�������ݡ�");
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->delete_temp("zong");
      tell_object(me, HIR"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
      tell_room(environment(me), HIW + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n" NOR,  ({ me }));
    
}
