// boots.c Ƥѥ
#include <ansi.h> 
#include <armor.h>

inherit BOOTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"����֮ѥ"NOR, ({ "boots18"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("long", "����һ˫����֮ѥ�����Ա����㲿�����ӿ�����ٶȡ�\n");
		set("value", 2600);
set("armor_prop/armor", 60);
		set("armor_prop/dodge", 11);
set("armor_prop/dexterity",10);
	}
	setup();
}