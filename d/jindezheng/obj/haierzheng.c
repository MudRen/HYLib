#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC"ˮ���մɺ�����"NOR, ({"haier zheng", "zheng"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�������Ҥ���Ƶ��մɾ�Ʒ��\n");
		set("unit", "��");
		set("value", 10000);
	}
}
