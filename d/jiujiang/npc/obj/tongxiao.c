
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("ͭ��", ({ "tong xiao","tong","xiao" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ��ͭ��������һ��һ�\n");
		set("value", 2000);
		set("material", "steel");
	}
	init_sword(170);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n������䡣\n");

	setup();
}
