#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(YEL"��֮��"NOR, ({ "light pao", "lightpao" }));
	set("long", YEL"����һ����֮�ۣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/intelligence",10);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 380);
	set("armor_prop/damage", 320);
	set("armor_type", TYPE_ARMOR);
	setup();
}	
