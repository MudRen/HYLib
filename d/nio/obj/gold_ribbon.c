// gold_ribbon.c �������

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�������", ({ "gold ribbon", "ribon", "dai" }));
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
