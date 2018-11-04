// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tmqidu_poison"; }

string chinese_name() { return "���Ŵ���ɢ"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIB"�Һ�һ������ɫ���࣬ȫ������������ס�Ĳ�������\n"NOR, environment(me), me);
                tell_object(me, HIB "��ֻ��ȫ����������ȫ�����Ҫ����һ�㡣��\n" NOR );
if (random(3)==0 && (int)me->query("qi")< 100000)
{
if (me->query("qi") > me->query("qi")/2)
        me->set("qi", me->query("qi")/2);
tell_object(me,HIG"�������������!\n"NOR);
}
else if (random(3)==1  && (int)me->query("qi")< 100000)        
{
if (me->query("jing") > me->query("jing")/2)
        me->set("jing", me->query("jing")/2);
tell_object(me,HIG"��ľ���������!\n"NOR);
}
else 
{
if (me->query("neili") > me->query("neili")/2  && (int)me->query("qi")< 100000)
        me->set("neili", me->query("neili")/2);
tell_object(me,HIG"�������������!\n"NOR);
}
        if (!me->is_busy())
        me->start_busy(4);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
