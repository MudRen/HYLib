// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW "���Ѫ�ߵİ���" NOR, ({ "whitecloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǽ�����İ��۵����沼��Ѫ�ߡ�\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 112);
	}
	setup();
}
