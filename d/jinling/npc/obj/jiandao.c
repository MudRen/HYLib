// brass_staff.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({ "jian dao" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ͨͨ�ļ�����\n");
		set("value", 120);
		set("material", "steel");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_blade(10);
	setup();
}
