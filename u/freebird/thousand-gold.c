// thousand.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(YEL "һǧ����Ʊ" NOR, ({"thousand-gold", "thousand-gold_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-gold");
                set("no_drop",1);
		set("long", "һ�����ֵһǧ�����ӵĽ�Ʊ��\n");
		set("unit", "��");
		set("base_value", 10000000);
		set("base_unit", "��");
		set("base_weight", 6);
	}
	set_amount(1);
}

