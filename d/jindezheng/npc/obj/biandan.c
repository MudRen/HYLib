#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("�ⵣ",({"biandan","bian dan","dan"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	set("value",50);
	set("long","�����Ƴɵıⵣ�����������õ�������\n");
	set("material","bamboo");
	}
	init_staff(5);


	setup();
}
