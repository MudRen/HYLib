#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name(HIR"�����"NOR, ({ "earth shield", "earthshield" }));
	set("long", HIR"����һ�氫��ܣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 27000);
	set("material", "gem");
	set("armor_prop/armor", 100);
	set("armor_prop/damage", 50);
	set("armor_type", TYPE_SHIELD);
	setup();
}	
