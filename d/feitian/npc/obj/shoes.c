// female-shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIM"��ʽľ��"NOR, ({ "shoes", "shoes"}) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "˫");
		set("long", "һ˫��ľͷ���ɵ�Ь�ӡ�\n");
		set("value", 0);
		set("armor_prop/armor", 50 );
		set("female_only", 1);
	}
	setup();
}
