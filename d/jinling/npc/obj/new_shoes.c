// shoe.c

#include <armor.h>
inherit BOOTS;


void create()
{
	set_name( "��Ь", ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ˫�ֹ���ϸ��Ь�ӡ�\n");
		set("material", "cloth");
		set("unit", "˫");
		set("armor_prop/armor", 1 );
	}
	setup();
}


