// kurong-changong.c ��������
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������Ŀ���������\n");

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
	||  me->query_skill("linji-zhuang",1)
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
    "status_msg" : HIG + me->name()+"�����ɬ֮����˫Ŀ�ʹ����ӡ�" NOR,
    "start_my_msg" : "����ϥ���£���Ŀ��ʲ��Ĭ�˿���������ֻ����������������ʼ�����ڻ����ζ���\n",
    "start_other_msg" : me->name()+"��ϥ���£���Ŀ��ʲ�������ƺ�������һ������֮�С�\n",
    "halt_msg" : "$N˫��һ�֣�������ȭ����������Ѹ�ٽ������ڡ�\n",
    "end_my_msg" : "������������������һ�����죬�����������ڵ������̧�����۾���\n",
    "end_other_msg" : "ֻ��"+me->name()+"���������۾����������ֵ���������ȥ��\n"
          ]);
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}


