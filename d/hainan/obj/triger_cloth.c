// bear_cloth.c ����Ƥ by ksusan 10/06/97
#include <ansi.h>

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"��Ƥ��ȹ"NOR, ({ "skirt","cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "���ϻ�Ƥ���ɵĶ�ȹ,�����кڻƽ�֯�Ļ��ƣ�\n");
		set("unit", "��");
		set("value", 1200);
		set("material", "leather");
		set("armor_prop/armor", 40);
		set("armor_prop/armor_vs_force", 40);
		set("armor_prop/attack", -6);
		set("armor_prop/dodge", -4);
	}
	setup();
}

int query_autoload() { return 1; }
