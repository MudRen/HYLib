// majia.c
// by steel
#include "armor.h"
#include "ansi.h"

inherit ARMOR;

void create()
{
	set_name(HIR "����ս��" NOR, ({ "cw_armor","armor"}) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n��������Ŀ��ס��������,�˵������ɷǷ�!\n");
		set("unit", "��");
		set("no_put", 1);
//		//set("value", 100000);
		set("material", "����");
		set("armor_prop/armor", 200);
		set("armor_prop/personality", 10);
		set("armor_prop/defense", 20);	
	}
	setup();
}

