#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("���ָ",({"jinjiezhi","jiezhi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","ֻ");
	set("long","��������Ľ��ָ��\n");
	set("value",1000);
	set("material","gold");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",24);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$NС������Ĵ�����$n��\n"NOR);
	set("unequip_msg",HIC"$N�����İ�$nժ��������\n"NOR);
	setup();
}

