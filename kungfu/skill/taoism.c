// taoism.c ��ѧ�ķ�
// modified by Venus Oct.1997

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    int lvl;

    lvl = (int)me->query_skill("taoism", 1);

    if( (int)me->query("shen") < 0 )
   return notify_fail("���а��̫�أ��޷�������ʦ������\n");

    if(me->query("gender") == "����" && lvl > 39)
   return notify_fail("�����һ�������������Ժ���ԭ����û������֮
�����޷��������������仯֮����\n");

    if ((me->query_skill("buddhism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1))
   return notify_fail("������"+RANK_D->query_respect(me)
      +"������ţ���ôȴ��ѧ�����ķ���\n");

    if ((me->query_skill("poison",1) > 1))
   return notify_fail("������"+RANK_D->query_respect(me)
      +"�Ѿ�ѧ��аħ����Ķ�������ôȴ��ѧ�����ķ���\n");

    return 1;
}

int practice_skill(object me)
{
    return notify_fail("��ʦ����ֻ�ܿ�ѧϰ����ߡ�\n");
}
