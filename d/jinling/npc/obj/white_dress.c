// white_dress.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�׳�����", ({ "white dress", "dress" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 3200);
		set("long", "һ����ɫ��˿��Ů�������������������ޱȡ�\n");
		set("material", "cloth");
		set("armor_prop/armor", 11);
	}
	setup();
}
