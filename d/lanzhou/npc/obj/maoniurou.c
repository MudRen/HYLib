// maoniurou.c ��ţ��

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("��ţ��", ({ "maoniu rou", "rou" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���տ���������ĺ�ţ�⡣\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 25);
        }
    setup();
}

