// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIB"ˮ֮����"NOR, ({ "guo dong", "guodong" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"�����ز���һ��ˮ֮������\n"NOR);
		set("unit", "��");
		set("value", 1000);
		set("food_remaining", 22);
		set("food_supply", 120);
		set("material", "bone");
	}
	setup();
}
