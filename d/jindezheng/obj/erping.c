#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIC"�������˫��ƿ"NOR, ({"ping", "shuangerping"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�������Ҥ���Ƶ��մɾ�Ʒ��\n");
		set("unit", "��");
		set("value", 20000);
		set("max_liquid", 200);
	}
}
