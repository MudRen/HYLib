// iceshock.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	me->receive_damage("jing", 85);
	me->receive_wound("qi", 85);

me->start_busy(3);
	me->apply_condition("iceshock", duration - 1);

	tell_object(me, HIB "���е��⺮�ƶ������ˣ�\n" NOR );
	if( duration < 1 ) return 0;

	return CND_CONTINUE;
}
