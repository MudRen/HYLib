#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name("����",({"yuzhuo","zhuozi"}));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","ֻ");
	set("long","����һֻ���������̳ɵ�����\n");
	set("value",5000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",3);
	set("armor_prop/armor",14);
	set("armor_prop/dodge",3);
	}
	set("wear_msg",HIC"$NС������Ĵ�����$n��\n"NOR);
	set("unequip_msg",HIC"$N�����İ�$nժ��������\n"NOR);
	setup();
}


