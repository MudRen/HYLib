#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({ "huang_jiasha", "cloth" }) );
      set("long","һ����ɫ������.\n");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 14);
		set("armor_prop/dodge", 13);
	}
	setup();
}
