
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
       return __DIR__"cloudforce/" + func;
}
 
int effective_level() { return 12;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 10;
}

