//Cracked by Kafei
// chahua.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"ɽ�軨"NOR, ({"cha hua", "cha"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ʢ���Ĳ軨�����䲻ͬɫ�Ĵ󻨿�����һ֦��������Ȼʮ�������Ƿ�Ʒ��\n");
		set("unit", "��");
        set("material", "wood");
	}
}
