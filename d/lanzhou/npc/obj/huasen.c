// huasen.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��ը����", ({"huasheng", "peanut"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ļ����ס�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 2);
		set("food_supply", 40);
	}
}