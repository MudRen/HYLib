// 

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"��ع�ʵ"NOR, ({ "earth guo", "earthguo" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ع�ʵ��\n");
		set("unit", "��");
		set("value", 1700);
		set("food_remaining", 22);
		set("food_supply", 160);
		set("material", "bone");
	}
	setup();
}
