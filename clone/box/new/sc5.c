// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"���ĶǴ�"NOR, ({ "surcoat5"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ��Ƥ�ʵĹ��ĶǴ������Ա���������\n");
		set("value", 1600);
		set("armor_prop/dodge", 13);
set("armor_prop/intelligence",12);
set("armor_prop/armor", 37);
	}
	setup();
}
