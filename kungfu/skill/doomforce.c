// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int effective_level() { return 13;}

int valid_learn(object me)
{

        return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("��Ѫ��ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}


 
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
	return 50;
}

string perform_action_file(string action)
{
        return __DIR__"doomforce/" + action;
}