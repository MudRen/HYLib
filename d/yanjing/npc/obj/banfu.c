// blade.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name("�師",({"banfu","ban fu","fu","axe"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",5000);
		set("material", "iron");
		set("long","һ�ѽ���İ師��\n");
		set("wield_msg","$N������γ�һ�ѳ������$n�������С�\n");
		set("unequip_msg","$N�����е�$n�������䡣\n");
	}
	init_axe(20);
	setup();
}
