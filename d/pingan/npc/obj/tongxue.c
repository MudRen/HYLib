// man-shoe.c
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("ͭѥ", ({ "tong xue", "tongxue","xue" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "tong");
		set("unit", "˫");
		set("long", "����һ˫��ͭ������ѥ�ӣ����Ա���˫�š�\n");
		set("value", 2000);
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("armor_prop/dodge", -3);
		set("armor_prop/armor", 4);
	}
	setup();
}
