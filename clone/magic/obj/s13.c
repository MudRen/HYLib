#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIY"�������"NOR, ({ "ice ring", "icering" }));
	set("long", HIY"����һ��������£��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "ö");
	set("value", 32000);
	set("material", "gem");
	set("armor_prop/armor", 60);
	set("armor_prop/damage", 60);
	set("armor_type", TYPE_FINGER);
	setup();
}	
