// music yangzhou' ����

inherit ITEM;
inherit F_FOOD;

void create()
{       string *name= ({"��������", "������ͷ", "����", "���", "����"});
        set_name( name[random(5)],({"food"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 10);
		set("food_supply", 40);
	}
}
