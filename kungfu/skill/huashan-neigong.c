// huashan-neigong.c ��ɽ�ڹ�
// Modified by Venus Oct.1997

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
    int i = (int)me->query_skill("huashan-neigong", 1);
 
//  if ((int)me->query_skill("zixia-shengong", 1) < 10)
//   return notify_fail("�����ϼ�񹦻�򻹲�����\n");

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
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1)) return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ɽ�ڹ�����\n");

//    if ((int)me->query("shen") < (int)pow(i/10, 2) * 100)
//   return notify_fail("�����̫���ˡ�\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��ɽ����ֻ����ѧ(learn)�������������ȡ�\n");
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : MAG + me->name()+"ͷ�������������ɫ����" NOR,
    "start_my_msg" : "����ϥ������˫Ŀ���գ�������һ�������絤�������һ����Ϣ�������Ѩ��������������֮����\n",
    "start_other_msg" : me->name()+"��ϥ����������˫�����ճ�ȭ����һ�ᣬͷ��ð����������\n",
    "halt_msg" : "$N΢һ��ü������Ϣѹ�ص������һ������վ��������\n",
    "end_my_msg" : "�㽫��Ϣ����������ʮ�����죬���ص��ֻ����ȫ��ů����ġ�\n",
    "end_other_msg" : me->name()+"����һ������һ���½�վ�����������о���һ����\n"
  ]);
}

string exert_function_file(string func)
{
    return __DIR__"huashan-neigong/" + func;
}