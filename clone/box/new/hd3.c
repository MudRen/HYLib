// toukui.c ͷ��
#include <ansi.h>  
#include <armor.h>
 
inherit HEAD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"����ͷ��"NOR, ({ "helmet3" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "��");
		set("long", "����һ������ͷ�������Ա���ͷ����\n");
		set("value", 1700);
set("armor_prop/intelligence",12);
set("armor_prop/armor", 67);
set("armor_prop/defense", 15);
	}
	setup();
}