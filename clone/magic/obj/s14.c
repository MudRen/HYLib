#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIR"��˳���"NOR, ({ "ice armor", "icearmor" }));
	set("long", HIR"����һ����˳��ۣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 32000);
	set("material", "gem");
	set("armor_prop/armor", 150);
	set("armor_prop/damage", 50);
	set("armor_type", TYPE_ARMOR);
	setup();
}	
