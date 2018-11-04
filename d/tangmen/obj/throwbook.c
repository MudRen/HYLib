// throwbook.c

inherit ITEM;

void create()
{
	set_name("���Ű����ܾ�", ({ "book", "shu"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"���Ű����ܾ�\n"
			"����һ�������������������ܽ�����İ����ܾ���\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"throwing",	// name of the skill
			"exp_required":	100000,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	200	// the maximum level you can learn
		]) );
	}
}

