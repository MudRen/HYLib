// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("ͭ����",({"tong shoutao","tongshoutao","shoutao"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","˫");
		set("material","tong");
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("long", "����һ˫��ͭ�Ƴɵ����ף���������˫�֡�\n");
		set("armor_prop/armor",8);
		set("value",1000);
	}
	setup();
}
