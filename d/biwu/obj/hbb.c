inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ͷ", ({"dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������̫Ӳ����ͷ��\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
