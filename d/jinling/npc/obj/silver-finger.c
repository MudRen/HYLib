
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("����ָ", ({ "silver-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ��������Ľ�ָ��������Ϊ���������С��������\n");
		set("unit", "ֻ");
		set("value", 700);
		set("material", "silver");
		set("armor_prop/damage", 2);
//		set("weapon_prop/damage", 2);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

