#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(RED"���촸"NOR, ({ "bighammer", "hammer" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "steel");
		set("long", "����һ�ѳ��صĺ��촸�����������ǳ�������\n");
		set("value", 1500);
//                set("no_put", 1);
//                set("no_drop", 1);
 		set("wield_msg", "$N�ó�һ��$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_hammer(800, TWO_HANDED);
	setup();
}
