// zhusun.c �����ݥ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����ݥ", ({"zhusun", "zhu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ˬ�ڵ����ز�-��ݥ��\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 50);
	}
}
