// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"���۶Ǵ�"NOR, ({ "surcoat15"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ��Ƥ�ʵ����۶Ǵ������Ա���������\n");
		set("value", 2500);
		set("armor_prop/dodge", 17);
set("armor_prop/intelligence",18);
set("armor_prop/armor", 37);
	}
	setup();
}
