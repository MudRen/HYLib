#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}


int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("��Ļ����ڹ���򻹲������޷����ɱ���ķ���\n"); if ( 
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
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("shenyuan-gong",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) ) return notify_fail("�㲻��ɢ�˱����ڹ�������ѧɱ���ķ�����\n");
	return 1;
}

int practice_skill(object me)
{
       return notify_fail("ɱ���ķ�ֻ����ѧ(learn)�������������ȡ�\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shayi-xinfa/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"ɱ����������������" NOR,
    "start_my_msg" : HIR"����������������ɱ������������ʼ��������ת��\n"NOR,
    "start_other_msg" : me->name()+"ȫ��������ȫ�������������˳����������е�ɱ���ޱ�������\n",
    "halt_msg" : "$Nüͷ��չ��ɱ����ʧ���ָ���ƽʱ��ģ����\n",
    "end_my_msg" : "�޾���ɱ�⻺��ɢ��ȫ�������ۣ�������һ������\n",
    "end_other_msg" : "ֻ��"+me->name()+"���۾�����ɱ�⣬�������ָֻ���ԭ״��\n"
          ]);
}
