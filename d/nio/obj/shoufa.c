// shoufa.c ������Ѩ��ͼ��

inherit ITEM;

void create()
{
	set_name("������Ѩ��ͼ��", ({ "shoufa tujie", "tujie", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure", 1);
		set("unit", "��");
		set("long", "�Ȿ�ַ�����ϸ�ػ�������Ѩ��ͼ�Լ�������Ѩ�ַ�������ͼ�⣬��Ȼ������˵���Լ������������������ַ��ľ���ȴ�ǿ��Եġ�\n");
		set("value", 30);
		set("material", "paper");
		set("skill", ([
			"name":	"hand",		// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
