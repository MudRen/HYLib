//Cracked by Roath
// zhuyeqing.c ��Ҷ��

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ƿ", ({"zhuye qing", "zhuye", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
һ������װ��Ҷ��ľ�ƿ���˾ƾ�˵Դ�� ���ӻ��塱����ɫ���̣���Ө͸����
LONG
        );
		set("unit", "��");
		set("value", 160);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 20,
		"drunk_apply": 8,
	]));
}
