// roupian.c ˮ����Ƭ

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ˮ����Ƭ", ({"roupian", "pian"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�軹ð�����ݵ�ˮ����Ƭ���������湻����\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 6);
		set("food_supply", 60);
	}
}
