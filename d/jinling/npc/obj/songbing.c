// songbing.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ɱ�", ({ "songbing", "bing","song","muffee" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ϻõ��ɱ���\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
