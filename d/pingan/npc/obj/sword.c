// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({ "chang jian" , "changjian" , "jian","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�����������Լ��ʮ�������ҡ�\n");
		set("value", 400);
		set("material", "gang");
	}
	init_sword(25);

	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");

	setup();
}
