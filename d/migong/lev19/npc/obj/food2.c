// dumpling.c ����
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"���"NOR, ({"mian bao", "mianbao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 6);
		set("food_supply", 60);
	}
}
