// color_head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�಼ͷ��", ({ "headband" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ͨ���಼ͷ��\n");
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

