// huwan.c ����

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"��â����"NOR, ({ "wrists8"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		
		set("value", 1900);
		set("material", "cloth");
		set("armor_prop/armor", 32);
set("armor_prop/strength",6);
set("armor_prop/damage", 7);
	}
	setup();
}
