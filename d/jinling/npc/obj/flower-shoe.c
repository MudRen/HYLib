// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "�廨СЬ", ({ "flower-shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ˫����ϸ����СЬ����Ů���ӵĶ�����\n");
		set("material", "cloth");
		set("unit", "˫");
		set("value", 700);
		set("armor_prop/armor", 1 );
		set("female_only", 1);
	}
	setup();
}
