// white_cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���׳���", ({ "white cloth", "cloth" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ѩ��ɫ�ĳ������ü����ı���˿��֯�ɣ�����������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

