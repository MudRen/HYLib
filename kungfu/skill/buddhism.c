// buddhism.c �����ķ�
// Modified by Venus Oct.1997

inherit SKILL;
void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    if( (int)me->query("guilty") > 0 )
      return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���\n");
    if( (int)me->query_skill("taoism",1) > 1 )
      return notify_fail("��ѧ��ţ���ӵ��ķ����޷����������ķ���\n");
    if( (int)me->query_skill("poison",1) > 1 )
      return notify_fail("��ѧ��а�Ŷ������޷����������ķ���\n");
    return 1;
}

int practice_skill(object me)
{
    return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

