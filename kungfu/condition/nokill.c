// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object ob;
	if (duration < 1) {
		tell_object(me, "��Ĺٸ������ڹ��ˣ�\n");
		return 0;
	}
	me->apply_condition("nokill", duration - 1);
	return 1;
}
