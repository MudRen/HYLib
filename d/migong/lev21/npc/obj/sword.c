// gangdao.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("ħ������", ({ "magic sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����λε�ħ�������������ߵĳ���������\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����ʡ�\n");
	}
	init_sword(200);
	setup();
}
