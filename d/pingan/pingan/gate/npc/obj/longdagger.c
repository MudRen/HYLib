
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name( HIR "��ӧ" NOR + "��ǹ" NOR, ({ "changqiang" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ�ĳ�ǹ��������Լ��ʮ�������ҡ�\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������¡�\n");
	}
	init_dagger(25);
	setup();
}
