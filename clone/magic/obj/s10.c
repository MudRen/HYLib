#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIW"��ӡ��ָ"NOR, ({ "earth ring", "earthring" }));
	set("long", HIB"����һ����ӡ��ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "ö");
	set("value", 27000);
	set("material", "gem");
	set("armor_prop/armor", 50);
	set("armor_prop/damage", 50);
	set("armor_type", TYPE_FINGER);
	setup();
}	
