#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name(YEL"�����"NOR, ({ "dead shield", "deadshield" }));
	set("long", YEL"����һ������ܣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
        set("armor_prop/karay",15);
        set("armor_prop/percao",15);
	     set("armor_prop/dexterity",5);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 480);
	set("armor_prop/damage", 100);
	set("armor_type", TYPE_SHIELD);
	setup();
}	
