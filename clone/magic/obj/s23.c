#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIR"���編��"NOR, ({ "dark cloth", "darkcloth" }));
	set("long", HIR"����һ�����編�£��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("armor_prop/intelligence",15);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 380);
	set("armor_prop/damage", 200);
	set("armor_type", TYPE_ARMOR);
	setup();
}	
