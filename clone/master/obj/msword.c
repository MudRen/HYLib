// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("�ݼ���", ({ "wangsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѽ���ֻ����ָ���������\n");
		set("value", 4000);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N�ӳ�Ƥ�����г��һ��ֻ����ָ���$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĳ�Ƥ���ʡ�\n");
	}
	init_sword(180);
	setup();
}
