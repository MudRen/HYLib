//Cracked by Roath
// zhuangyuan.c ״Ԫ��

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"��ƿ"NOR, ({"zhuangyuan hong", "zhuangyuan", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
һ������װ״Ԫ��ľ�ƿ����˵�˾ƺ��Ĵ�
LONG
        );
		set("unit", "��");
		set("value", 170);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "״Ԫ��",
		"remaining": 20,
		"drunk_apply": 8,
	]));
}
