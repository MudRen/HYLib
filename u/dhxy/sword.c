#pragma save_binary
 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC "���佣" NOR, ({ "zwsword" }) );
	set_weight(7000);
        set("owner","������");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "�����䵱��ɽ֮�������䱦����\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        set("task",1); 
        set("no_put_in",1); 
	}
	init_sword(500);
	setup();
}
