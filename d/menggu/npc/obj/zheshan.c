// Mr.music  yangzhou's ����

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("̴����",({"shanzi"}));
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
		set("long", "����һ����������ͨ�����ӡ�\n");
		set("wield_msg", "$N৵�һ��˦�������ӡ�\n");
		set("unequip_msg", "$N�������е�$n��\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(20);
	setup();
}
