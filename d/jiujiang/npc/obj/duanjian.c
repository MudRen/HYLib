
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�̽�", ({ "duan jian","jian","sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�Ѷ̽���\n");
		set("value", 2000);
		set("material", "steel");
	}
	init_sword(70);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������Ľ��ʡ�\n");

	setup();
}
