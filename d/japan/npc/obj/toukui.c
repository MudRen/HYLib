// shield.c

#include <armor.h>

inherit HEAD;

void create()
{
      set_name("ͷ��", ({ "tou kui", "kui"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
              set("material", "coin");
              set("unit", "��");
              set("value", 1000);
              set("armor_prop/armor", 15);
		set("armor_prop/defense", 3);
	}
	setup();
}
