// boots.c Ƥѥ
#include <ansi.h> 
#include <armor.h>

inherit BOOTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"��ӥ֮ѥ"NOR, ({ "boots16"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "˫");
		set("long", "����һ˫��ӥ֮ѥ�����Ա����㲿�����ӿ�����ٶȡ�\n");
		set("value", 2400);
set("armor_prop/armor", 68);
		set("armor_prop/dodge", 11);
set("armor_prop/dexterity",19);
	}
	setup();
}
