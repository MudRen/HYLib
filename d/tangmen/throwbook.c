// book3.c

#include <armor.h>

//inherit ITEM;
inherit HANDS;

void create()
{
	set_name("������", ({ "iron hand", "hand", "shu", "book" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"�׽����ƪ\n"
			"����һ�������ƣ����氼��͹͹���������β����ĳ��档\n");
		set("value", 500);
		set("material", "steel");
		set("armor_prop/armor", 3 );
		set("skill", ([
			"name":	"parry",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	10,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	29	// the maximum level you can learn
		]) );
	}
}

