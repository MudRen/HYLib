

#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("�廨�ڿ�", ({ "color pants","pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��Ů�Գ��õ��廨�ڿ㣬ɢ����һ�����ص���ζ��\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

