// gold_belt.c ������

#include <armor.h>

inherit WAIST;

void create()
{
	set_name("������", ({ "gold belt", "belt", "yaodai" }));
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
