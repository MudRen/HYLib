// fonxanforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

 
int effective_level() { return 12;}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 30;
}

