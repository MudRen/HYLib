// daode-jing.c ���¾�
#include <ansi.h>

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
    int lvl;

    lvl = (int)me->query_skill("daode-jing", 1);

	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/emei"))
		return notify_fail("����ͼѧϰ���¾������ƺ����޽�չ��\n");
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/emei") && lvl > 100)
		return notify_fail("����ͼѧϰ���¾������ƺ����޽�չ��\n");

    if( (int)me->query("shen") < 0 )
   return notify_fail("���а��̫�أ��޷��������¾���\n");

    if(me->query("gender") == "����" && lvl > 339)
   return notify_fail("�����һ�������������Ժ���ԭ����û������֮�����޷��������������仯֮����\n");

    return 1;
}

int practice_skill(object me)
{
    return notify_fail("���¾�ֻ�ܿ�ѧϰ����ߡ�\n");
}


void skill_improved(object me)
{
	if (me->query_skill("daode-jing", 1) > 200) {
		tell_object(me,HIW"\n�㽫���¾�����ѧ����ѧ�໥���գ�ͻȻ���������׹�ץ�ʹ����ƾ�Ȼ����һ����أ�\n\n"NOR);
if (me->query_skill("jiuyin-baiguzhua", 1) > 200)
{
		if (me->query_skill("jiuyin-baiguzhua", 1) > me->query_skill("jiuyin-shenzhua", 1))
			me->set_skill("jiuyin-shenzhua", me->query_skill("jiuyin-baiguzhua", 1));
		me->delete_skill("jiuyin-baiguzhua");
}
if (me->query_skill("cuixin-zhang", 1) > 200)
{
		if (me->query_skill("cuixin-zhang", 1) > me->query_skill("jiuyin-shenzhang", 1))
			me->set_skill("jiuyin-shenzhang", me->query_skill("cuixin-zhang", 1));
		me->delete_skill("cuixin-zhang");
}
	}
}
