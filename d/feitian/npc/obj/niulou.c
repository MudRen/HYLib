// shou si.��˾

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ţ������", ({"niu lou", "niulou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���Ƕ����ʿ��Ե�ţ������\n");
		set("unit", "��");
		set("value", 140);
		set("food_remaining", 1);
		set("food_supply", 80);
	}
}
