#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name(HIC"���ƶ�"NOR, ({ "ice shield", "iceshield" }));
	set("long", HIC"����һ�����ƶܣ��������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 32000);
	set("material", "gem");
	set("armor_prop/armor", 120);
	set("armor_prop/damage", 20);
	set("armor_type", TYPE_SHIELD);
	setup();
}	
