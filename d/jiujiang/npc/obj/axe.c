// ����.

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("����", ({ "axe"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͷ��\n");
		set("value", 1500);
		
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��غ󱳡�\n");
	}
	init_axe(30,150,150);
	setup();
}
