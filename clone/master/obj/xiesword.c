// xiesword.c : master xie's weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����ү�Ľ�", ({ "xiesword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѻ���Ƥ��,�ƽ��̿ڵĳ���,���߳�����,������Լ��ʮ�������ҡ�\n");
		set("value", 4000);
		set("material", "steel");
	}
	init_sword(175);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");

// The setup() is required.

	setup();
}
