// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIB"ħ���ʵ"NOR, ({ "dark guo", "darkguo" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ��ħ���ʵ��\n");
		set("unit", "��");
		set("value", 2700);
		set("food_remaining", 30);
		set("food_supply", 500);
		set("material", "bone");
	}
	setup();
}
