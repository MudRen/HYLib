#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("ľ��", ({ "blade", "blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һ�����²��ɵ������޼����ֵ�ľ����\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(5);
	setup();
}