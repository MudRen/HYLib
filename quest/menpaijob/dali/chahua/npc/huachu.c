//Cracked by Kafei
// AceP

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name( CYN "����" NOR , ({ "huachu", "chu" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��С��ͷ��ľ�ѣ���ͷ���ǻ����ֻ����ݵĺù��ߡ�\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N����һ��$n���������е�������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_hammer(10);
	setup();
}
