// color_head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�廨ͷ��", ({ "color-headband", "headband" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����Ŵ�컨���ͷ��Ů����������ͷ���á�\n");
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 21);
		set("female_only", 1);
	}
	setup();
}

