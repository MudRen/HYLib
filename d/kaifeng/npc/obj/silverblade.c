//silverblade.c
//LOTS 1998/10/14
#include <weapon.h>

inherit BLADE;

void create()
{
set_name("����", ({ "silverblade", "blade", "dao" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 8000);
		set("material", "silver");
		set("long", "����һ�Ѱ�߶೤������,����������һ��,������\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("shaolin",1);
	}
	init_blade(575);
	setup();
}
