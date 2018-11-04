// 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"Å£ÅÅ"NOR, ({ "niu pai", "niupai" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¿é¿¾µÃÏãÅçÅçµÄÅ£ÅÅ¡£\n");
		set("unit", "¿é");
		set("value", 800);
		set("food_remaining", 16);
		set("food_supply", 80);
		set("material", "bone");
	}
	setup();
}
