
#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("��ɴȹ", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������ϸɴ֯�ɵ�ȹ��.\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 37);
	}
	setup();
}
