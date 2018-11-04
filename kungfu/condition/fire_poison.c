// fire_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "fire_poison"; }

string chinese_name() { return "���޶���"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIR"һ���Һ���ȫ��ȼ����" HIG "����ɫ"
               HIR "�Ļ��档\n"NOR, environment(me), me);
                tell_object(me, HIY "ֻ��ȫ�������ޱȣ�������ȼ���" HIG "����"
               HIR "ֱ�����衣��\n" NOR );
if ((int)me->query("qi") < 100000)
{
        me->receive_wound("qi", me->query("qi")/8);
        me->receive_damage("qi", me->query("qi")/9);
}else    me->receive_wound("qi", 2000);
        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
