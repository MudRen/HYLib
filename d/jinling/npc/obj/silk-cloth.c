
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("˿�����", ({ "silk-cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����Ǯ�˲Żᴩ��˿����£�����ȥ���÷ǳ������\n");
		set("unit", "��");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 1);
		set("female_only", 0);
	}
	setup();
}

