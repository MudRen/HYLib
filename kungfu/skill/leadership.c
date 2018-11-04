// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s;

	s = me->query_skill("leadership", 1);
        if( s%10==9 && (int)me->query("per") < s/5) {
		tell_object(me, HIW "��������ѧ����֮���������������ˡ�\n" NOR);
		me->add("per", 2);
	}
}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

