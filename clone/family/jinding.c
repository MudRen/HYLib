// jinkuai.c ���

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "��" NOR, ({ "jin ding", "jin", "ding" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ���ƳγεĽ𶧡�\n");
                set("value", 800000);
		set("unit", "��");
	}
}


