// bonze_drug.c

#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "����ͬ������ͨ�����ˣ�\n");
		return 0;
	}
	me->apply_condition("sexman", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}
