

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ֽ�", ({ "gangjian", "jian","sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ٱ��õĸֽ���\n");
		set("value", 1500);
	    set("super",2);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(20,100,100);
	setup();
}
