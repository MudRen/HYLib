// wudu-xinfa

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("shen") > -10000)
		return notify_fail("��ϰ�嶾�ķ������ĺ��������С�\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("�嶾�ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
