//Mr.music yangzhou ����

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("����", ({ "tiejia","jia" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("value", 1000);
                set("material", "steel");
		set("armor_prop/armor", 15);
	}
	setup();
}
