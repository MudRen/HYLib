// bojuan.c

inherit ITEM;

void create()
{
	set_name("����", ({ "bo juan", "bo", "juan" }));
	set_weight(50);
//	set("no_drop", "�������������뿪�㡣\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("treasure",1);set("unit", "��");
		set("long",
			"����һ��������д�� ��\n"
			"ׯ�ӡ���ң�Ρ����ƣ��֮����ڤ���ߣ����Ҳ�������ɣ������ǧ�������\n");
		set("value", 500);
		set("material", "silk");
		set("skill", ([
			"name":	"beiming-shengong",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	50,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100,	// the maximum level you can learn
			"min_skill":	20	// the maximum level you can learn
		]) );
	}
}

