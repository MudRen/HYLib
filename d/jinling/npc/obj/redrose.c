// color_head.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name( HIR "��õ��" NOR , ({ "red rose" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������ޱȵĺ�õ�塣\n");
		set("unit", "��");
		set("value", 2000);
		set("material", "rose");
		set("armor_prop/armor", 11);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

