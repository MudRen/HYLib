//Cracked by Roath
// Food: songguo.c 
// By Marz@XKX 11/12/96

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIG"Ұ�ɹ�"NOR, ({"guo", "song guo"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ŵ������������Ұ�ɹ���\n");
		set("unit", "��");
		set("value", 200);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}


