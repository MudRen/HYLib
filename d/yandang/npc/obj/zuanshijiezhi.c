#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("��ʯ��ָ",({"zuanshijiezhi","jiezhi"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","ֻ");
	set("long","����ͷ׵���ʯ��ָ��\n");
	set("value",2000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",24);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$NС������Ĵ�����$n��\n"NOR);
	set("unequip_msg",HIC"$N�����İ�$nժ��������\n"NOR);
	setup();
}


