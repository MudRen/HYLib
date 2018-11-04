// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
    me->receive_wound("jing", 20);
    me->start_busy(random(3));
//    me->receive_wound("kee", 10);
//    me->receive_damage("sen", 10);
    me->receive_damage("qi", 60);
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "���е��߶������ˣ�\n" NOR );
	return 1;
}
