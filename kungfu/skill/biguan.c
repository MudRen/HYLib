// biguan.c

inherit SKILL;

void skill_improved(object me)
{}
int valid_learn(object me)
{
	return notify_fail("��ֻ��ͨ����biguan��ͨ�ζ��������Ż����Ź���.\n");
}
int practice_skill(object me)
{
	return notify_fail("��ֻ��ͨ����biguan��ͨ�ζ��������Ż����Ź���\n");
}
