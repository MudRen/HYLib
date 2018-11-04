// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
string *dodge_msg = ({
        "$n��Ӱһ�Σ����Ǽ�Ų��$N�ı���\n",
        "$n΢΢����һ����������Ʈ�����⡣\n",
        "$n˫��΢΢�趯����������һƬ��Ҷ����������Ʈ����\n",
        "$n˫��΢�ߣ���һֻ��ݵ����ӷ��˿���\n",
        "$n����һ���������˵������⡣\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="dodge");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 )
		return notify_fail("�������̫���ˣ�������̫��ò���\n");
	me->receive_damage("qi", 30);
	return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return __DIR__"ghosty-steps/" + action;
}

