// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ�һ�С��������¡�������׾ٵıܿ���һ����\n",
        "$n������ת��һʽ�����˾��ơ������Դܿ����ߣ����˿�ȥ��\n",
        "$n�������ϰ���һ�С��ѾƷ��ɡ���һ��ת����������֮�⡣\n"
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
		return notify_fail("�������̫���ˣ��������������²���\n");
	me->receive_damage("qi", 30);
	return 1;
}
int effective_level() { return 10;}

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
        return __DIR__"zuixian-steps/" + action;
}
