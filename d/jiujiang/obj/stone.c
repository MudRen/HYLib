// 

#include <weapon.h>
inherit ITEM;

void create()
{
	set_name("ʯͷ", ({ "stone","shi","tou"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ʯͷ��\n");
		set("value", 0);
		
	
	
	}
	
	setup();
}
