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


       if((int)me->query_skill("bingxue-xinfa",1) < 100)
                return notify_fail(HIY "��ı�ѩ�ķ���Ϊ������\n" NOR);

         if((int)me->query_skill("snowstep",1) < 100)
                return notify_fail(HIY "���÷ѩƮ�㲻��������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "snowstep")
                return notify_fail("�����ڼ����������ǡ�ѩ�衹������\n");                                                                                 
      if( me->query_temp("piao")   )
      return notify_fail("������ʹ��ѩ�裡\n");
       
     msg = HIW"$N������������Ʈ������˷�����$N��Ӱ��,��ͬ����ѩ�裡\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      if (improve > 100) improve =100;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      me->set_temp("piao",1);  
      me->add("neili", -150);    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("snowstep") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense",- improve);
      me->delete_temp("piao");
      tell_object(me, HIW"��ɢȥ�������۵�����������������������\n"NOR);
      tell_room(environment(me), HIW + me->name()+"����Խ��Խ����ɢȥ�˻���Ĺ�����\n" NOR,  ({ me }));
    
}
