#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIR"��֮��ָ"NOR, ({ "fire ring", "firering" }));
	set("long", HIR"����һ����֮��ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "ö");
	set("value", 20000);
	set("material", "gem");
	set("armor_prop/armor", 20);
	set("armor_prop/damage", 30);
	set("armor_type", TYPE_FINGER);
	setup();
}	
