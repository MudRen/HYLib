#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIB"��ħ����"NOR, ({ "dark head", "darkhead" }));
	set("long", HIB"����һ����ħ���֣��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/dexterity",15);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 200);
	set("armor_prop/damage", 10);
	set("armor_type", TYPE_HEAD);
	setup();
}	
