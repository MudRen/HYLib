#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"������"NOR, ({ "biyuzan", "yuzan" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 70);
		set("material", "stone");
	}
}
