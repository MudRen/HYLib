// liji.c ץ���Ｙ

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "ץ���Ｙ" NOR, ({"zhuachao liji", "liji"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ץ���Ｙ�ᡢ�̡����⽹���ۣ��ǡ��Ĵ�ץ����֮һ��\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}