// ճ�⡣�����ز���:-)

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ճ��", ({"nian gao", "gao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���Ǹ������ز�ճ�⡣\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
