#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("��׹��",({"yuzuizi","yuzui"}));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","ֻ");
	set("long","һֻС���������׹�ӡ�\n");
	set("value",1000);
	set("material","stone");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",14);
	set("armor_prop/dodge",3);
	}
	set("wear_msg",HIC"$NС������Ĵ�����$n��\n"NOR);
	set("unequip_msg",HIC"$N�����İ�$nժ��������\n"NOR);
	setup();
}


