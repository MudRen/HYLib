// brass_staff.c

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("����", ({ "pipa", "staff" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���������������á�\n");
		set("value", 1200);
		set("material", "steel");
		set("wield_msg", "$N�ó�һ��������$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_staff(110);
	setup();
}
