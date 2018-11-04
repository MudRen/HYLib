// thousand.c

#include <ansi.h>

inherit MONEY;

void create()
{
	set_name(HIG "һǧ����Ʊ" NOR, ({"thousand-cash", "thousand-cash_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-cash");
		set("long", "һ�����ֵһǧ�����ӵ���Ʊ��\n");
		set("unit", "��");
		set("base_value", 100000);
		set("base_unit", "��");
		set("base_weight", 1);
                set("no_steal",1);
                set("no_beg",1);
                set("no_drop",1);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
	}
	set_amount(1);
}
