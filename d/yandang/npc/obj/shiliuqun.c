#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("ʯ��ȹ", ({ "skirt", "shiliuqun" }) );
      set("long","һ����ɫ��ʯ��ȹ.\n");
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/dodge", 11);
	}
	setup();
}
