// necklace.c �Ǵ�
#include <ansi.h>   
#include <armor.h>
 
inherit SURCOAT;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name((order[random(13)])+"��ˮ�Ǵ�"NOR, ({ "surcoat8"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("long", "����һ��Ƥ�ʵ���ˮ�Ǵ������Ա���������\n");
		set("value", 1900);
		set("armor_prop/dodge", 14);
set("armor_prop/intelligence",14);
set("armor_prop/armor", 30);
	}
	setup();
}
