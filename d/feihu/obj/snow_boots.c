// shoe.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(HIW "��ɽѥ" NOR, ({ "snow boots", "shoes"}) );
       	set("long", "����һ˫ר�������Ǳ�ɽ��ѥ��,ѥ�׶����˶���\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "wood");
		set("unit", "˫");
		set("value", 50000);
		set("armor_prop/armor", 3 );
		set("armor_prop/personality", 3);
		//set("female_only", 1);
	}
	setup();
}
