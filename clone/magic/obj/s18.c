#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name(YEL"����֮��"NOR, ({ "light shield", "lightshield" }));
	set("long", YEL"����һ������֮�ܣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/karay",10);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 500);
	set("armor_prop/damage", 100);
	set("armor_type", TYPE_SHIELD);
	setup();
}	
