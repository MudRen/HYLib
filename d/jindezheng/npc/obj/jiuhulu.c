#include <weapon.h>
inherit HAMMER;
inherit F_LIQUID;

void create()
{
	set_name("�ƺ�«", ({"jiuhulu", "hulu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ɫ΢�Ƶ�װ�ƺ�«��\n");
		set("unit", "��");
		set("value", 500);
		set("max_liquid", 20);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "�յ���",
		"remaining": 20,
		"drunk_apply": 20,
	]));
init_hammer(110);
setup();
}
