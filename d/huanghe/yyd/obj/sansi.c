// sansi.c ����˿

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����˿", ({"kousansi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������𡱣�������������������˿�������У�״��Сɽ��Ԣ��ϼ���Բ���������⡣\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 1);
		set("food_supply", 45);
	}
}