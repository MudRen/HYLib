// twig.c
// By jpei

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("֦��", ({ "twig", "zhi tiao", "zhi" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ϵ�֦������������£��о������������̵��ˡ�\n");
		set("value", 1);
		set("material", "wood");
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N���������е�$n��\n");
	}
	init_sword(2);
	setup();
}
