
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("���ָ", ({ "gold-finger", "finger" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һֻ�ƽ����Ľ�ָ��������Ϊ���������С��������\n");
		set("unit", "ֻ");
		set("value", 2000);
		set("material", "gold");
		set("armor_prop/damage", 2);
		set("armor_prop/personality", 2);
		set("female_only", 0);
	}
	setup();
}

