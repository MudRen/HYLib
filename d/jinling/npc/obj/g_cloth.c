// g_cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�ٲ��Ʒ�", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
         "����һ���ٲ���Ʒ����������ͣ�������������á�\n");
		set("value", 100);
		set("armor_prop/armor", 25);
		set("material", "cloth");
	}
	setup();
}
