
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�����ڿ�", ({ "pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����Գ��õĺ�ɫ�ڿ㡣\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 0);
	}
	setup();
}

