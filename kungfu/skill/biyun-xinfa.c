// biyun-xinfa.c �����ķ�
// cleansword

inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("biyun-xinfa", 1);

        if ( (me->query("family/family_name") != "����"))
                return notify_fail("�����ķ������Ŷ�����, �����ŵ��Ӳ���!\n");
                                    
        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���Ų�Ҫ�������޸����Ե��ˣ����޷�������ı����ķ���\n");

        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("��Ļ����ڹ���򻹲������޷��������ķ���\n");
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
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bibo-shengong",1)  ||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����\n");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"biyun-xinfa/" + func;
}