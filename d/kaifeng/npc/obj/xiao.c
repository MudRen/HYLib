// xiao.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("С¥һҹ������", ({ "dao", "xiao", "blade" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "gold");
		set("long", "�����Ǵ�˵�е�'Բ���䵶'.\n");
		set("wield_msg", "$N৵ĳ��һ��$n\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("shaolin",1);
	}
	init_blade(750);
	setup();
}
