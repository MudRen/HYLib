// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(HIB "��˿����" NOR, ({ "cloak body","cloakbody"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIB"\n����һ����˿����,�������侫��!\n"NOR);
               set("value", 19000);
		set("unit", "��");
		set("armor_prop/armor", 560);
		set("armor_prop/defense", 20);	
	}
	setup();
}
