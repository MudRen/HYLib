// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"����"NOR, ({ "dan gao", "dangao" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�鿾���������ţ�š�\n");
		set("unit", "��");
		set("value", 700);
		set("food_remaining", 12);
		set("food_supply", 60);
		set("material", "bone");
	}
	setup();
}
