// ������
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIB"�������˱�"NOR, ({ "canglang bian", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������˱ޣ������ޱȡ��д󺣵�������\n");
		set("value", 10000);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(680);
	setup();
}
