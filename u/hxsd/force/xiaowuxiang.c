// xiaowuxiang.c С���๦
// by secret
// 1997-1-16
//

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xiaowuxiang", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸����С���๦��\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧС���๦��\n");

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ����������������������С���๦��\n");

	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("ҪѧС���๦����ı��ֻ������ɣ� \n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
		|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	||  me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧС���๦��\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("С���๦ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}