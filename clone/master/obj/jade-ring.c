
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(HIC "�����ָ" NOR, ({ "jade-ring"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ε����ָ\n");
		set("unit", "��");
		set("value", 1000);
		set("armor_prop/armor", 10);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");


	}
	setup();
}
