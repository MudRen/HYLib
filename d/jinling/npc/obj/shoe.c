// shoe.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( "���׿�ѥ", ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","һ�����ɵ�Ь��������ʿ��ϲ������\n");
		set("material", "cloth");
		set("unit", "˫");
		set("value", 500);
		set("armor_prop/armor", 11 );
		set("female_only", 0);
	}
	setup();
}
