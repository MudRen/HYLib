// wuwo.c

#include <ansi.h>
int exert(object me)
{       

        int nh=me->query_skill("bahuang-gong");

        if ((int)me->query_skill("bahuang-gong", 1) < 160)
                return notify_fail("��İ˻�����Ψ�Ҷ�����Ϊ��������\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������\n");
        
      if( me->query_temp("yun_wuwo")   )
                return notify_fail("����������Ψ�Ҷ���\n");

        write(MAG"��Ǳ��Ψ�Ҷ����־���ֻ�������֮��Ψ�Ҷ���������������š�\n"NOR);

        message_vision(HIW"ֻ��$N��������һ����������¶��һ˿Ц�ݡ�\n"NOR, me);
        me->add_temp("apply/armor", nh/2);
        me->add_temp("apply/defense", nh/2);
        me->add_temp("apply/attack", nh/2);
        me->add_temp("apply/sword", nh/2);
        me->add_temp("apply/parry", nh/2);
        me->add_temp("apply/strength", 10);
        me->add_temp("apply/dexerity",10);
        me->add_temp("apply/intelligence",10);
        me->add_temp("apply/percao",10);
        me->set_temp("yun_wuwo", 1);  
        me->add("neili", - 300);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, nh :), nh * 3/2 );
        return 1;
}
void remove_effect(object me, int nh)
{
      me->add_temp("apply/strength", -10);
      me->add_temp("apply/dexerity",-10);
      me->add_temp("apply/intelligence",-10);
      me->add_temp("apply/percao",-10);
      me->add_temp("apply/armor", -nh/2);
      me->add_temp("apply/defense", -nh/2);
      me->add_temp("apply/parry", -nh/2);
       me->add_temp("apply/attack", -nh/2);
        me->add_temp("apply/sword", -nh/2);
      me->delete_temp("yun_wuwo");
      tell_object(me, HIR"��ɢȥ�ˡ�Ψ�Ҷ����ķ������ָֻ���ԭ�����㡣\n"NOR);
}
