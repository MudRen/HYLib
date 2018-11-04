// goldblade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("Óù´Í½ğµ¶", ({ "goldblade", "dao", "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("value", 100000);
		set("material", "gold");
		set("long", "ÕâÊÇÒ»°ÑÓù´Í½ğµ¶,Ô¼Ò»³ß³¤,ÉÁÉÁ·¢×Å½ñ¹.\n");
		set("wield_msg", "$N³é³öÒ»°ÑÃ÷»Î»ÎµÄ$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unequip_msg", "$N½«ÊÖÖĞµÄ$n²åÈëÑü¼äµÄµ¶ÇÊ¡£\n");
		set("shaolin",1);
	}
	init_blade(1500);
	setup();
}
