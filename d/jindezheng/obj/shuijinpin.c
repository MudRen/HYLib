#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"���ˮ��ƿ"NOR, ({"jinpin", "pin"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������Ƶ��մɾ�Ʒ��\n");
		set("unit", "��");
		set("value",10000);
		set("max_liquid", 100);
	}
}
