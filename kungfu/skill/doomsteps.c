// pyrobat-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ�һ�С��黳���ȡ�����������ıܿ���һ����\n",
        "$n������ת��һʽ�����ѵ�ˮ����ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�ʹ����ϸ���ɷ��ơ���$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ�һ�С��׺׳��졹�����Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ�ʹ�������ӷ������о����յرܿ���$N��һ�С�\n",
        "$n��������һ�Σ�һ�С�����չ�᡹��һ��ת����������֮�⡣\n"
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
		return notify_fail("�������̫���ˣ���������Ѫ������\n");
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
        return __DIR__"doomsteps/" + action;
}
