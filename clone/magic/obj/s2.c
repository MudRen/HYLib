// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit CLOTH;

void create()
{
	set_name(HIR "��ɽ�����Ӽ�" NOR, ({ "stone body","stonebody"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", HIR"\n����һ����ɽ�����Ӽ�,�������侫��!\n"NOR);
               set("value", 19000);
		set("unit", "��");
		set("armor_prop/armor", 550);
		set("armor_prop/defense", 10);	
	}
	setup();
}
