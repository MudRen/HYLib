// niurou.c ԭ������ţ��

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "ԭ������ţ��" NOR, ({"niurou"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڣ����������˱ǣ�����ϸ�����õķ���ţ��\n");
		set("unit", "��");
		set("value", 190);
		set("food_remaining", 2);
		set("food_supply", 50);
	}
}