// shield.c ��ɫ�̶� 
#include "ansi.h"
#include "armor.h"
 
inherit SHIELD;
 
void create()
{
	set_name(HIR"��ɫ�̶� "NOR, ({ "metal shield", "metalshield" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
set("long", HIR"����һ����ɫ�̶�,�������侫�¡���������Ų�֮һ��\n"NOR);
               set("value", 15000);
		set("armor_prop/armor",100);
		set("armor_prop/damage",10);
}
	setup();
}