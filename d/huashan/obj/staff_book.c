// ITEM: /d/huashan/obj/staff_book.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name("�ȷ�ͼ��", ({ "staff book", "book" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ���ȷ�ͼ�⡣\n");
        set("treasure",1);
	set("value", 500);
	set("material", "paper");
	set("skill", ([
			"name":	"staff",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost": 15+random(15),// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		      ]) );
}
