
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�첼�Ƕ�", ({ "red underwear", "underwear" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ������޲����ɵĶǶ����������ż���ƻ�������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

