// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("ľ��", ({ "mublade", "mublade" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Сľ�����������һ��СС�����֡�\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(5);
	setup();
}
