// wineskin.c  �ƴ�
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIC"����֮ˮ"NOR, ({"ice water", "icewater"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ����֮ˮ�Ĵ�Ƥ�������װ�ðˡ������ķ���֮ˮ��\n");
		set("unit", "��");
		set("value", 2000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "����֮ˮ",
		"remaining": 160,
		"drunk_apply": 20,
	]));
}
