
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name( HIR "����һ��ľͷ������Ƭ" NOR, ({ "rustysword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѱ���һ��ľͷ������Ƭ������������ߣ�\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N�ѱ�������$n�γ��������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_sword(85);
	setup();
}
