// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("ͭ��",({"tong jia","tongjia","jia"}));
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("material","tong");
		set("long", "����һ����ͭ�Ƴɵļ��У����������ϰ���\n");
		set("armor_prop/armor",15);
		set("value",4000);
	}
	setup();
}
