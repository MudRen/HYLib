// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��", ({ "bu" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ƥ");
		set("long", 
         "����һƥ��ͨ�Ĳ����������ͣ�������������á�\n");
		set("value", 100);
		set("armor_prop/armor", 1);
		set("material", "cloth");
	}
	setup();
}
