//Cracked by Kafei
// bow.c

#include <ansi.h>
#include <weapon.h>

inherit __DIR__"bow.c";

void create()
{
	set_name("����", ({ "short bow", "bow"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("bow_power", 22);
		set("str_requirement", 20);
		set("material", "wood");
		set("long", "����һ����ͨ��ľ�ƶ���\n");
		set("wield_msg", "$N�ӱ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ر���\n");
		set("unequip_msg", "$N�����е�$n��ر���\n");
		
	}	
	init_bow(8);
	setup();
}
