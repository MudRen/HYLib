// tielianzi.c
#include "ansi.h" 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name(HIY"��"NOR, ({ "jin hua", "jinhua", "hua" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ƽ����İ�����\n");
		set("unit", "��");
		set("value", 0);
		set("base_unit", "��");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 220);	//Here the damage=int_throwing, added by King
	}
	set_amount(50);
	init_throwing(220);
	setup();
}
