// Obj:/d/npc/obj/xitang.c
// llm 99/07
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ϲ��", ({"xitang", "tang"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ɫ�ĵ�ϲ�ǡ�\n");
		set("unit", "��");
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
