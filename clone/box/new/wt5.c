// huwan.c ����

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"���軤��"NOR, ({ "wrists5"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		
		set("value", 1700);
		set("material", "cloth");
		set("armor_prop/armor", 29);
set("armor_prop/strength",5);
set("armor_prop/damage", 5);
	}
	setup();
}
