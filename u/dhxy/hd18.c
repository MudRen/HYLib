// toukui.c ͷ��
#include <ansi.h>  
#include <armor.h>
 
inherit HEAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"��âͷ��"NOR, ({ "helmet18" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ����âͷ�������Ա���ͷ����\n");
		set("value", 3200);
set("armor_prop/intelligence",10);
set("armor_prop/armor", 22);
set("armor_prop/defense", 11);
	}
	setup();
}