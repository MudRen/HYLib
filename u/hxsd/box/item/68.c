#include <weapon.h>
inherit RING;
void create()
{
        set_name( "���ָ", ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ָ��\n");
                set("no_drop",1);
                set("no_get",1);
                set("rigidity",50);
	        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        	set("unwield_msg", "$N�����ϵ�$n���뻳�С�\n");
	}
	init_ring(80);
	setup();
}
