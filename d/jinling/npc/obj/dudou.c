
#include <armor.h>


inherit WAIST;

void create()
{
	set_name("˿��Ƕ�", ({ "silk underwear", "underwear" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����˿�����ɵĶǶ�����������ԧ��Ϸˮ������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 1200);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 1);
	}
	setup();
}

