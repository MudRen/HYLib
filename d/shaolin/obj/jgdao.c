// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIY"��ַ�ħ��"NOR, ({ "fumo dao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ַ�ħ����\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(500);
	setup();
}
