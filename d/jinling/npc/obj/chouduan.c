// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���", ({ "silk" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ƥ");
		set("long", 
         "����һƥ��ͨ�ĳ�У��ʵ�����\n");
		set("value", 500);
		set("armor_prop/armor", 11);
		set("material", "cloth");
	}
	setup();
}
