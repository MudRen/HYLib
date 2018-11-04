#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("ֻ����վ���в���ʹ�ã�\n");


        if((int)me->query_skill("guiyuan-tunafa",1) < 100)
                return notify_fail(HIY "��Ĺ�Ԫ���ɷ���Ϊ������\n" NOR);

         if((int)me->query_skill("shuishangpiao",1) < 100)
                return notify_fail(HIY "���ˮ��Ư����������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "shuishangpiao")
                return notify_fail("�����ڼ����������ǡ�ˮ��Ư��������\n");                                                                                 
      if( me->query_temp("piao")   )
      return notify_fail("������ʹ��ˮ��Ư�����������ˮ��Ư����\n");
       
     msg = HIW"$NͻȻ����һ�����������Ȼ�����޹ǣ�����ҡ��" +
               "һ�С����㵹�����������ܳ����࣡\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      me->set_temp("piao",1);  
      me->add("neili", -(350-(int)me->query_skill("shuishangpiao",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("shuishangpiao") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense", - improve);
      me->delete_temp("piao");
      tell_object(me, HIC"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
      tell_room(environment(me), HIG + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n" NOR,  ({ me }));
    
}
