// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ƺ�", ({"jiuhu", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�Ƶľƺ������װ�ðˡ������ľơ�\n");
		set("unit", "��");
		set("value", 20);
		set("max_liquid", 15);
	}
          set("liquid",([
		"type": "alcohol",
		"name": "�յ���",
		"remaining": 15,
		"drunk_supply": 15,
	]));
}

