// guanfu.c
// LOTS 1998/10/17

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�ٷ�", ({ "guan fu", "cloth", "fu" }));
	set("long", "�����ղ���˵�ר�ùٷ�,�ǵ�������״͵�һƷ������.\n");
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 2000);
		set("armor_prop/armor", 200);
	}
	setup();
}
