#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"�������"NOR, ({ "earth armor", "eartharmor" }));
	set("long", HIC"����һ��������ף��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 27000);
	set("material", "gem");
	set("armor_prop/armor", 150);
	set("armor_prop/damage", 50);
	set("armor_type", TYPE_CLOTH);
	setup();
}	
