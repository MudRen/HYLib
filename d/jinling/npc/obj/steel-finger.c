
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("����ָ", ({ "steel-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ�������ɵĽ�ָ�������з�������ǣ���һ�������������\n");
		set("unit", "ֻ");
		set("value", 500);
		set("material", "steel");
		set("armor_prop/damage", 8);
		set("armor_prop/armor", 1);
		set("armor_prop/personality", -1);
		set("female_only", 0);
	}
	setup();
}

