// sword.c

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="array"; }

int form_array(object leader)
{
	object *member;

	member = leader->query_team();
	if( sizeof(member) > 4 )
		return notify_fail("�������������4�ˣ���һ�������С�\n");
	message_vision( HIG "$N�������˷�����վ����λ������ˡ����������󡹣�\n" NOR, leader);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"wudang-array/" + action;
}

