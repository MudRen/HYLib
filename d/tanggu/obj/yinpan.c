#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"����"NOR, ({ "yin pan", "pan" }));
        set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long", "һֻ���̡�\n");
                set("value", 3000);
		set("material", "silver");
	}
	setup();
}
