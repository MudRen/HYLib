#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIR"õ���Ǭ����"NOR, ({"qiankun hu", "hu"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�������Ҥ���Ƶ��մɾ�Ʒ��\n");
		set("unit", "��");
		set("value", 10000);
		set("max_liquid", 80);
	}
}
