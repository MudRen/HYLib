// bibo-shengong.c �̲���
// By Jungu
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı̲��񹦡�\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	||  me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�̲��񹦣���\n");

	return 1;
}

int practice_skill(object me)
{
    return notify_fail("�̲���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIC + me->name() + "�������£�������Ԩ����������������" NOR,
		"start_my_msg" : "���������£�˫Ŀ΢�գ�˫���������������̫�������˺�һ���������顣\n",
		"start_other_msg" : me->name() + "�������£�˫Ŀ΢�գ�˫���������������̫������紵����" + me->name() + "���ϵ����۾�Ȼ��Ϊ������\n",
		"end_my_msg" : "�㽫��Ϣ������һ��С���죬�������뵤�˫��һ��վ��������\n",
		"end_other_msg" : me->name() + "�����Ϻ��է�֣���������ȥ���漴˫��һ��վ��������\n"
	]);
}
string exert_function_file(string func)
{
    return __DIR__"bibo-shengong/" + func;
}