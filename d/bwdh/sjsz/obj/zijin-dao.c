//Cracked by Kafei
#include <ansi.h>
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(MAG"�Ͻ�"NOR, ({ "zijin dao", "dao" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���񱳱����Ͻ𵶣������Ϲ�����������ɭɭ��\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 500);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(250);
	setup();
}
