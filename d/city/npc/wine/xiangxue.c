//Cracked by Roath
// xiangxue.c ��ѩ��

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"��ƿ"NOR, ({"xiangxue jiu", "xiangxue", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
һ������װ��ѩ�Ƶľ�ƿ���˾��ֱ���Ϊ����׾ơ������ʸ��𴾺�
LONG
        );
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "��ѩ��",
		"remaining": 20,
		"drunk_apply": 5,
	]));
}
