// iceforce.c2

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("���ľ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

int effective_level() { return 13;}

int learn_bonus()
{
	return 3;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 15;
}

