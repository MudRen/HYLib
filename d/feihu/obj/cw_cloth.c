// cw_cloth
//by steel
#include "armor.h"
#include "ansi.h"
inherit CLOTH;
void create()
{	
        set_name(HIR"����ս��"NOR, ({ "cw_cloth", "cloth" }) );
	set_weight(6500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����ż��˵�˰ɣ���������....�Ǻǡ�\n");
		set("material", "cloth");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/armor", 100);
		set("armor_prop/defense", 10);	
   }	setup();
}