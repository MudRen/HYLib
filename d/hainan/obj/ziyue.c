#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name( MAG "���½�" NOR, ({ "ziyue sword", "sword" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "\n");
                set("value", 38000);
                set("material", "sapphire");
                set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 20);
                set("weapon_prop/personality", 10);
                set("rigidity", 40);
//                set("replica_ob", "/obj/longsword");
        }

        init_sword(650);
        setup();
}

