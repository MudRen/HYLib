//Cracked by Kafei
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;
void create()
{
	set_name(GRN"��β��"NOR, ({ "ewei bian", "bian" }));
//	set_color("$GRN$");
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������β�����ɵı��ӣ������ϵ�����һ�������롣\n");
		set("value", 7000);
		set("rigidity", 100000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
//		set("clone_ob", "/clone/weapon/eweibian");
	}
//	::create();
	init_whip(220);
	setup();
}
