// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("Ƥ��",({"pi jia","pijia","jia"}));
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material","pi");
		set("long", "����һ��ţƤ�Ƴɵļ��У����������ϰ���\n");
		set("armor_prop/armor",10);
		set("value",2000);
	}
	setup();
}
