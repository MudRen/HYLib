#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("��������",({"zhenzhu","xianglian"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","��");
	set("long","һ�����Ϻ����鴮�ɵ�������\n");
	set("value",2000);
	set("material","glass");
	set("armor_prop/personality",2);
	set("armor_prop/karma",2);
	set("armor_prop/armor",13);
	set("armor_prop/dodge",2);
	}
	set("wear_msg",HIC"$NС������Ĵ�����$n��\n"NOR);
	set("unequip_msg",HIC"$N�����İ�$nժ��������\n"NOR);
	setup();
}

