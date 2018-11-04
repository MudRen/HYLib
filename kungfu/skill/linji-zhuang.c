// linji-zhuang.c �ټ�ʮ��ׯ
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, np, nf, nh, ns, ts;
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);
	np = (int)me->query_skill("mahayana", 1);
	ns = (int)me->query("guilty");

//       	if ( me->query("couple/have_couple") )
//		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�ټ�ʮ��ׯ��\n");

	if ( me->query("gender") != "Ů��" )
		return notify_fail("��Ǵ�Ů֮�壬������ϰ�ټ�ʮ��ׯ��\n");


	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("�㲻����ã�ѧ���˸�����ټ�ʮ��ׯ��\n");

	if ( np <= nh && nh <= 100)
		return notify_fail("��Ĵ�����͹���Ϊ�������޷�����������ټ�ʮ��ׯ��\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������ټ�ʮ��ׯ��\n");

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
	|| me->query_skill("longxiang",1)
//	|| me->query_skill("mizong-xinfa",1)
	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunlong-shengong",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("zixia-shengong",1)  ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�ټ�ʮ��ׯ����\n");

	return 1;
}

int practice_skill(object me)
{
        return notify_fail("�ټ�ʮ��ׯֻ����ѧ(learn)�������������ȡ�\n");
}

void skill_improved(object me)
{
        switch (me->query_skill("linji-zhuang",1))
        {
              case 30:
                   tell_object(me, HIG "�����ׯ������! \n" NOR );
                   break;
              case 60:
                   tell_object(me, HIG "��֮��ׯ������! \n" NOR );
                   break;
              case 90:
                   tell_object(me, HIG "������ׯ������! \n" NOR );
                   break;
              case 120:
                   tell_object(me, HIG "�����ׯ������! \n" NOR );
                   break;
              case 150:
                   tell_object(me, HIG "���Сׯ������! \n" NOR );
                   break;
              case 180:
                   tell_object(me, HIG "����ڤׯ������! \n" NOR );
                   break;

        }
        return;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"���Ϻ�����֣�˫�ִ�����ϥ����" NOR,
    "start_my_msg" : HIR"��ϯ�ض������������죬���Ϻ��ʱ��ʱ�֣���Ϣ˳��������������\n"NOR,
    "start_other_msg" : MAG + me->name() +"ϯ�ض������������죬���Ϻ��ʱ��ʱ�֡�\n"NOR,
    "halt_msg" : HIW"$N����һ����������Ϣ�������˻�ȥ��վ��������\n"NOR,
    "end_my_msg" : HIC"�㽫��Ϣ���˸�С���죬���ص���չ�վ��������\n"NOR,
    "end_other_msg" : HIR"��һ���"+me->name()+"��������ĵ�վ��������\n"NOR
                    ]);
}

string exert_function_file(string func)
{
        return __DIR__"linji-zhuang/" + func;
}

