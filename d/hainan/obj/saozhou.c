#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("ɨ��",({"saozhou","sao zhou"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	set("long","���ر��Ƴɵ�ɨ�㣬ɨ���õġ�\n");
	set("material","wood");
	}
	init_staff(35);


	setup();
}
