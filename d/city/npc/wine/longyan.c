//Cracked by Roath
// longyanjiu.c ���Ҿ�

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"��ƿ"NOR, ({"longyan jiu", "longyan", "jiuping",}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", @LONG
һ������װ���ҾƵľ�ƿ���˾Ʋ����Ƕ��𣬲���ɫ���պ죬��������ҷ���
���ʳ����������𴼺󣬷����ء�
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
		"name": "���Ҿ�",
		"remaining": 20,
		"drunk_apply": 7,
	]));
}
