#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(YEL"����֮ѥ"NOR, ({ "light boots", "lightboots" }));
	set("long", YEL"����һ˫����֮ѥ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "˫");
	set("armor_prop/intelligence",5);
	     set("armor_prop/dexterity",5);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 180);
	set("armor_prop/damage", 120);
	set("armor_type", TYPE_BOOTS);
	setup();
}	
