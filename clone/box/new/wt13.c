// huwan.c ����

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"�ۺ׻���"NOR, ({ "wrists13"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		
		set("value", 2400);
		set("material", "cloth");
		set("armor_prop/armor", 67);
set("armor_prop/strength",15);
set("armor_prop/damage", 10);
	}
	setup();
}
