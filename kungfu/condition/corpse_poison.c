// corpse_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "corpse_poison"; }

string chinese_name() { return "��ʬ��"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + WHT"ȫ���������Ż�ˮ����ס��˻����ɢ��"
               "���������ŵĶ����\n"NOR, environment(me), me);
                tell_object(me, WHT "ֻ��ȫ�������Ƹ�����һ�㣬ɢ����һ�ɼ���"
               "�ŵĶ������\n" NOR );
if ((int)me->query("jing") < 100000)
        me->receive_wound("jing", me->query("jing")/8);
else    me->receive_wound("jing", 2000);
if ((int)me->query("qi") < 100000)
me->receive_damage("qi", me->query("qi")/9);
else    me->receive_wound("qi", 2000);
        
        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
