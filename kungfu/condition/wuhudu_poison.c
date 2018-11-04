// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "wuhudu_poison"; }

string chinese_name() { return "�廢�涾"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIY"�����涾���ģ��ְ��ؿڣ���ɫ���ڣ�ʹ����֡�\n"NOR, environment(me), me);
                tell_object(me, HIY "������Ŀ���ʹ��֣�������ǧ�������Ĵ��ǣ�\n" NOR );
if (random(3)==0 && (int)me->query("qi")< 100000)
{
        me->receive_wound("jing", me->query("jing")/8);
        me->receive_damage("jing", me->query("jing")/8);
tell_object(me,HIG"��ľ���������!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->receive_wound("qi", me->query("qi")/8);
        me->receive_damage("qi", me->query("qi")/8);
tell_object(me,HIG"�����Ѫ������!\n"NOR);
}
if (random(3)==0 && (int)me->query("max_neili") > 100)        
{
        me->add("max_neili", -60);
  tell_object(me,HIG"�������������!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->add("neili", -me->query("neili")/7);
  tell_object(me,HIG"�������������!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->set_temp("apply/attack", -80);
  tell_object(me,HIG"��Ĺ�����������!\n"NOR);
}
if (random(3)==0 && (int)me->query("qi")< 100000)        
{
        me->set_temp("apply/defense", -80);
  tell_object(me,HIG"��ķ�����������!\n"NOR);
}
        //if (!me->is_busy())
        me->start_busy(6);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
