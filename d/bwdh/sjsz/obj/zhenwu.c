//Cracked by Kafei
// zhenwu.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;
//#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIC"���佣"NOR, ({ "zhenwu sword", "zhenwu", "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"ֻ����������ͭ�̰�쵣���ͭ˿Ƕ������׭�ģ������䡱��\n");
                set("value", 7000);
                set("material", "steel");
		set("rigidity", 1500);
                set("wield_msg", 
			"ֻ������쬡���һ�����پ��������棬$N�������Ѿ�����һ�ѱ�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

        init_sword(420);
        setup();
//	::create();
}
