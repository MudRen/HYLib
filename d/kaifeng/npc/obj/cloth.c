// cloth.c /u/lots/obj/cloth.c
// LOTS 1998/10/19

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("����", ({"jin duan", "jin", "duan" }));
	set("long", "����һ��ո�µİײ���.\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 1000);
		set("armor_prop/armor", 50);
	}
	setup();
}
