// gangzhang.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("����", ({ "gangzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ȡ�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
	init_staff(20);
	setup();
}
