// goldblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("���ͽ�", ({ "goldblade", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100000);
		set("material", "gold");
		set("long", "����һ�����ͽ�,Լһ�߳�,�������Ž�.\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("shaolin",1);
	}
	init_blade(1500);
	setup();
}
