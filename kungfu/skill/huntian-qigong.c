// huntian-qigong.c
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huntian-qigong", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

//	if ( me->query("gender") == "����" && i > 49)
//		return notify_fail("���޸����ԣ���������������������Ļ���������\n");

//	if (i > 10 && ((int)me->query("shen") > t * 100 ||
//	    (int)me->query("shen") < t * (-100)))
//		return notify_fail("ѧ����������Ҫ������а��������а��������ò���ѽ��\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	||  me->query_skill("hunyuan-yiqi",1)
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
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIW + me->name()+"�����⣬���۷��衣" NOR,
    "start_my_msg" : "���������£�˫��ƽ����˫ϥ��Ĭ��ھ�����ʼ��������ķ���\n",
    "start_other_msg" : me->name()+"�������������£�˫��ƽ����˫ϥ���촽΢΢���������ϵ����ۿ�ʼ�Ķ�������\n",
    "halt_msg" : "$N��ɫһ����Ѹ��������վ��������\n",
    "end_my_msg" : "�������뵤�������ת�����������չ���˫��̧��վ��������\n",
    "end_other_msg" : "ֻ��"+me->name()+"˫��̧��վ��������������������������\n"
          ]);
}
string exert_function_file(string func)
{
        return __DIR__"huntian-qigong/" + func;
}
