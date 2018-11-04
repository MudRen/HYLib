// huagong-dafa.c ������
// by yucao
// Modified by Venus Oct.1997
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
    int i = (int)me->query_skill("huagong-dafa", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;
    if ((int)me->query_skill("force", 1) < 10)
   return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
    
//    if (i > 10 && (int)me->query("shen") > t * 2)
//   return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	if(i<=300)
	{
		if (i > 10 && -(int)me->query("shen") < t * 5) 
			return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
	}

    if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
   return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��������ʲ�ᣡ\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
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
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
   return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : BLU + me->name()+"�����ڵ���������Ϣ�����屻һ�����̻����š�" NOR,
    "start_my_msg" : "�����˵�������ڶ��������Ƴ����������������㻺��Ʈ������о����ھ���ʼ������ǿ�ˡ�\n",
    "start_other_msg" : me->name()+"��ϥ�����˹������彥����һ����������Χ��\n",
    "halt_msg" : "$N˫��һ�����������һ�����⣬��������һЦ��վ��������\n",
    "end_my_msg" : "��о�����ԽתԽ�죬�Ϳ�Ҫ������Ŀ����ˣ�����æ�ջض��غ���Ϣ����Цһ��վ��������\n",
       "end_other_msg" : me->name()+"����һ����Ц������һ�����̣�վ���������ӵ�ɨ���ڳ�����һ�ۡ�\n"
  ]);
}
string exert_function_file(string func)
{
    return __DIR__"huagong-dafa/" + func;
}

