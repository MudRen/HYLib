#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIB"��������"NOR, ({ "earth pf", "mearth" }));
	set("long", HIB"����һ���������磬�������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 28000);
	set("material", "gem");
	set("armor_prop/armor", 80);
	set("armor_prop/damage", 30);
	set("armor_type", TYPE_ARMOR);
	setup();
}	
