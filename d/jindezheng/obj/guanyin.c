#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"�������ӹ�����"NOR, ({"shenxiang", "xiang"}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�������Ҥ���Ƶ��մɾ�Ʒ��\n");
		set("unit", "��");
		set("value", 10000);
	}
}
