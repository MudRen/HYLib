#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(YEL"�����ָ"NOR, ({ "dark ring", "darkring" }));
	set("long", YEL"����һ�������ָ���������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/intelligence",5);
	     set("armor_prop/dexterity",5);
	set("armor_prop/strength",8);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 100);
	set("armor_prop/damage", 100);
	set("armor_type", TYPE_FINGER);
	setup();
}	
