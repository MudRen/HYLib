#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIB"ˮ֮��ָ"NOR, ({ "water ring", "waterring" }));
	set("long", HIB"����һ��ˮ֮��ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "ö");
	set("value", 22000);
	set("material", "gem");
	set("armor_prop/armor", 30);
	set("armor_prop/damage", 30);
	set("armor_type", TYPE_FINGER);
	setup();
}	
