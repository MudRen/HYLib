// liyu.c �Ǵ�����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "�Ǵ�����" NOR, ({"tangcu liyu", "liyu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���⽹���ۣ������ʿڵ��Ǵ����㡣\n");
		set("unit", "��");
		set("value", 250);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}