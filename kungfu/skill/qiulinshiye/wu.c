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


	if( (int)me->query_skill("qiulinshiye", 1) < 60 )
                return notify_fail("�������ʰҶ�����ߡ�\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫����\n");

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "qiulinshiye")
                return notify_fail("�����ڼ���������������ʰҶ��\n");                                                                                 
      if( me->query_temp("tmwu")   )
      return notify_fail("������ʹ������ʰҶ���������������\n");
       
     msg = HIW"$N��������Ҷ���裬�������Ȧ����Ʈ����" +
               "����Ҫ���У�ȴ���������������\n" NOR;
      
      me->start_busy(1);
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      
      me->set_temp("tmwu",1);  
      me->add("neili", -(350-(int)me->query_skill("qiulinshiye",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("qiulinshiye") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense", - improve);
      
      me->delete_temp("tmwu");
      tell_object(me, HIC"��ɢȥ�������۵������������������������������У��������ġ�\n"NOR);
      tell_room(environment(me), HIG + me->name()+"ȫ���ͷһ�����죬ɢȥ�˻���Ĺ�����\n" NOR,  ({ me }));
    
}
