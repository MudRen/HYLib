// wineskin.c  �ƴ�
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"ˮ��"NOR, ({"niu nai", "niunai"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װţ�̵Ĵ�Ƥ�������װ�ðˡ�������ţ�̡�\n");
		set("unit", "��");
		set("value", 1000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "ţ��",
		"remaining": 60,
		"drunk_apply": 9,
	]));
}
