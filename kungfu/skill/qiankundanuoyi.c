// qingkundanuoyi.c Ǭ����Ų��
// modified by Venus Jan.1998

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
   if( (int)me->query("shen") < 0 )
   return notify_fail("���а��̫�أ��޷�����Ǭ����Ų�ơ�\n");

   if(me->query("gender") == "����")
   return notify_fail("�����һ�������������Ժ���ԭ����û������֮
�����޷���������Ǭ�������仯֮����\n");

   return 1;
}

int practice_skill(object me)
{
    return notify_fail("Ǭ����Ų��ֻ��ѧϰ������\n");
}
