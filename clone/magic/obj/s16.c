#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIC"���ƿ�"NOR, ({ "ice head", "icehead" }));
	set("long", HIC"����һ�����ƿ����������һЩ��ֵ����\n"NOR);
	set("weight", 400);
	set("unit", "��");
	set("value", 32000);
	set("material", "gem");
	set("armor_prop/armor", 80);
	set("armor_prop/damage", 20);
	set("armor_type", TYPE_HEAD);
	setup();
}	
