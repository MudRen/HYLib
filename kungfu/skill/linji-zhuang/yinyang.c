// yinyang.c

#include <ansi.h>

int exert(object me)
{       
        int nh, improve;
        nh = (int)me->query_skill("linji-zhuang");
        improve = nh * 3 / 2;
        if( me->is_fighting() )
                return notify_fail("ս�����˹���������\n");

        if (me->is_busy() )
        return notify_fail("����æ���ģ�\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

        if( (int)me->query("neili") < 120 )
                return notify_fail("�������������\n");
        
      if( me->query_temp("yun_yinyang")   )
                return notify_fail("�����������ټ�ʮ��ׯ�ġ��������־���\n");

        write(HIW"�㰵��������ׯ����ȡ�����������۾��������پ�����������\n"NOR, me);

        message_vision(HIW"ֻ��$N����ƣ������ת˲��㾫���ӡ�\n"NOR,me);

        me->add("eff_jing", improve );
        me->add("jing", improve);
        me->add("eff_jingli", improve);
        me->add("jingli", improve);
        me->add("max_qi", improve);
        me->add("qi", improve);
        me->set_temp("yun_yinyang", 1);  
        me->add("neili", - 150);    
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2);
        return 1;
}
void remove_effect(object me, int improve)
{      
      me->add("eff_jing", - improve);
      me->add("max_qi", - improve);
      me->add("eff_jingli", - improve);
      me->delete_temp("yun_yinyang");
      tell_object(me, HIR"����ټ�ʮ��ׯ���������־��˹���ϣ�����������ɫ�ö��ˡ�\n"NOR);
}
