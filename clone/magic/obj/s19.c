#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"������"NOR, ({ "light yi", "lightyi" }));
	set("long", HIY"����һ�������£��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/dexterity",15);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 800);
	set("armor_prop/damage", 200);
	set("armor_type", TYPE_CLOTH);
	setup();
}	
