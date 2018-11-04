// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("������", ({ "zi_zhuzhang" , "zhuzhang" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����⾫�ֵ������ȡ�\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(130);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�������е�$n��\n");


	setup();
}
