//Mr.music yangzhou ��Ƥ

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��Ƥ", ({ "lang pi","langpi","pi" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {

		set("material", "pi");
		set("value", 1000);
		set("unit", "��");
		set("armor_prop/armor", 50);
	}
	setup();
}
