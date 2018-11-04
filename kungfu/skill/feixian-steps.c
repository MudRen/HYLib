// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nһ�С��������ࡹ�������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ������Ҳ������ѱ����߳�֮�⡣\n",
	"$nʹ������ת��Ȩ�����������ɵ�������\n",
	"$n����һ�㣬һ�С���Ӱ���ࡹ�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С��綯��⡹����������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С�������������������\n",
	"����$nһ�С��������١�ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취�����ɲ�����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("����������������������������ɲ�����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}
int effective_level() { return 20;}

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
	return 10;
}

string perform_action_file(string action)
{
        return __DIR__"feixian-steps/" + action;
}

