// fish.c �����
// By jpei

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�����", ({ "white fish", "da baiyu", "baiyu", "fish", "yu" }) );
	set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������һ�߶೤�Ĵ���㡣\n");
		set("unit", "��");
		set("value", 500);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("material", "fish");
	}
	setup();
}

int finish_eat()
{
	set_name("���", ({ "fish bone", "yu gu", "bone", "gu" }) );
	set_weight(150);
	set("long", "һ���еþ�������ͷ��\n");
	set("unit", "��");
	set("value", 0);
	set("material", "bone");
	return 1;
}
