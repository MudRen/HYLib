// anqibook.c

inherit ITEM;

void create()
{
	set_name("�����ַ�����", ({ "book", "shu"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�����ַ�����\n"
			"����һ������ʹ�õ������顣\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"throwing",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	60	// the maximum level you can learn
		]) );
	}
}

