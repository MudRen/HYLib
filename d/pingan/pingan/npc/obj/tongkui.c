// huyao.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("ͭ��" , ({"tong kui","tongkui","kui"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����ͭ�Ƴɵ�ͷ�������Ա���ͷ����\n");
	set("value",1000);
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("material", "tong");
		set("armor_prop/armor", 8);
	}
	setup();
}
