// shoe.c
//by steel
#include "armor.h"
#include "ansi.h"

inherit BOOTS;

void create()
{
	set_name(HIR "����սѥ" NOR, ({ "cw_boots", "boots"}) );
       	set("long", "����һ˫���������սѥ,�������侫�¡�\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "˫");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/armor",50);
		set("armor_prop/attack", 10);
	}
	setup();
}
