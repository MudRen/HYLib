// color_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�������", ({ "color-cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�������ɫ�ĳ�������������ֻ�ʵ���ɷ�Ǻÿ���\n");
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 12);
		set("female_only", 1);
	}
	setup();
}

