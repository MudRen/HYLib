// shield.c ��ɫ�̶� 
#include "ansi.h"
#include "armor.h"
 
inherit SHIELD;
 
void create()
{
	set_name(HIB"�ѺϽ�� "NOR, ({ "plate shield", "plateshield" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
set("long", HIB"����һ���ѺϽ��,�������侫�¡���������Ų�֮һ��\n"NOR);
               set("value", 15000);
		set("armor_prop/armor",120);
		set("armor_prop/damage",20);
}
	setup();
}