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
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"biyun-xinfa/" + func;
}

