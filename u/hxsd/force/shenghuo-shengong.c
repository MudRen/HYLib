// shenhuo-shengong.c
// 4/5/97  -qingyun
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

//#include "force.h"

int valid_learn(object me)
{
        if (me->query_skill("force", 1) > 9)
        //		return valid_public(me);
	return notify_fail("��Ļ����ڹ�����Ҫ��һ����ߡ�\n");
        if (
        me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
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
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )  return notify_fail("�㲻��ɢ�˱����ڹ�������ѧʥ���񹦣���\n");
 return 1;
}

int practice_skill(object me)
{
	return notify_fail("ʥ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return SKILL_D("shenghuo-shengong/") + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"�������࣬��������һ�Ż���" NOR,
    "start_my_msg" : "����ϥ������˫�ִ�����ǰ�ɻ���״�������������þ����е���������һ����������ӿ�뵤�\n",
    "start_other_msg" : me->name()+"��ϥ������˫����ǰ�ش�ס���������࣬�������һ�Ż������¡�\n",
    "halt_msg" : "$N����΢΢����������������վ��������\n",
    "end_my_msg" : "�㽫������Ϣ��ͨ���������������۾���վ��������\n",
    "end_other_msg" : "ֻ��"+me->name()+"�����۾���վ��������ͷ�����۵İ�������Ʈɢ����\n",
    "heal_msg" : HIW"$N��ϥ������˫��ʮָ�ſ���������ǰ�����������֮״������"RED"ʥ����"HIW"��ʼ���ˡ�\n"NOR,
    "heal_finish_msg" : HIW"$N�������⸡�֣�һ���������Ҳ���������ʥ������λ�������οࣿ��������վ��\n"NOR,
    "heal_unfinish_msg" : "$N��̬ׯ�ϣ�����վ��������������Ѫ�죬�������ƻ�û����ȫ�ָ���\n",
    "heal_halt_msg" : "$N�����ͺ죬ͷ�����������������͵���һ����������������������\n",
    ]);
}
