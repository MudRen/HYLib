inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("��������", ({ "rxcy", "dish" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ������������Ϻô�ˡ�\n");
		set("unit", "��");
		set("food_remaining", 15);
		set("food_supply", 160);
		set("material", "food");
	}
	setup();
}
int finish_eat()
{
        set_name("����", ({"panzi"}));
        set("long", "һֻ���׶��񻨵ľ�̩�������ӡ�\n");
        return 1;
}
