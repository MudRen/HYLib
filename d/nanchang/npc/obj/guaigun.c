
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("�չ�", ({ "guai gun","gun"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������õĹչ���\n");	
		set("material", "steel");
		set("wield_msg", "$N����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�����˼��ϡ�\n");
	}
	init_staff(50);
	setup();
}
