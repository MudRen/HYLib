
#include <armor.h>

inherit NECK;

void create()
{
	set_name("������", ({ "gold-neck", "neck" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����Ӳӵ���������׹������һ���챦ʯ��\n");
		set("unit", "��");
		set("value", 5000);
		set("material", "gold");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 5);
		set("female_only", 0);
	}
	setup();
}

