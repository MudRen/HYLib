// wushidao.c ��ʿ��

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��ʿ��", ({ "wushi dao", "dao", "wushidao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѷ�����ʿ����������ʿ���������\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջ��ʡ�\n");
	}
	init_blade(125);
	setup();
}
