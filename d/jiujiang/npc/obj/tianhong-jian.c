
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIR"��콣"NOR, ({ "tianhong jian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������������Ͽ��š���졹���֡�\n");
		set("value", 1500);
		set("life",20);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(3,50);
	setup();
}
