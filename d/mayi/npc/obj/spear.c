
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("��ǹ", ({ "spear" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",1500);
		set("material", "iron");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�ŵ��˵��ϡ�\n");
	}
	init_club(100);
	setup();
}
