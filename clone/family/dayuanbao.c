// dayuanbao.c ���Ԫ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "���Ԫ��" NOR, ({ "da yuanbao", "da", "yuanbao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һֻ�ƳγεĽ�Ԫ����\n");
                set("value", 900000);
		set("unit", "ֻ");
	}
}

