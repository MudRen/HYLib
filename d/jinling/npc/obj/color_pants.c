
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�廨�ڿ�", ({ "color-pants", "pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��С�ò�����С�ķۺ�ɫ�廨�����ڿ㣬����������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 1);
	}
	setup();
}

