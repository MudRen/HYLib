// color_head.c

#include <armor.h>
#include <ansi.h>

inherit SHIELD;

void create()
{
	set_name( HIB "�껨ʯ" NOR , ({ "blue stone" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ɫ���껨ʯ��\n");
		set("unit", "��");
		set("value", 100);
		set("material", "stone");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

