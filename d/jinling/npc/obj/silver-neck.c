
#include <armor.h>

inherit NECK;

void create()
{
	set_name("������", ({ "silver-neck", "neck" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�������������������׹�Ͽ������⼪���ĸ��֡�\n");
		set("unit", "��");
		set("value", 1000);
		set("material", "silver");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

