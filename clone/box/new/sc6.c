// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"�̹ŶǴ�"NOR, ({ "surcoat6"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ��Ƥ�ʵ��̹ŶǴ������Ա���������\n");
		set("value", 1700);
		set("armor_prop/dodge", 13);
set("armor_prop/intelligence",13);
set("armor_prop/armor", 38);
	}
	setup();
}
