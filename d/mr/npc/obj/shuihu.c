// tiechui.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIB"ˮ��"NOR,({ "shui hu", "hu" }) );
         set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ��ˮ����\n");
                set("wield_msg", "$N�ó�һ��$n����\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_hammer(5);
        setup();
}

