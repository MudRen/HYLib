// xue-dao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name( HIR "Ѫ��" NOR , ({ "blood blade"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("treasure",1);
		set("unit", "��");
		set("long", HIR "����һ�Ѳ�������ı�����������ŵ�����ѪӰ��\n" NOR );
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(100);
	setup();
}