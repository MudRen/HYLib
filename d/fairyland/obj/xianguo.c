// xianguo.c
// By jpei

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ʹ�", ({"xian guo", "fruit", "guo"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����֪����Ұ�������������㡣\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
