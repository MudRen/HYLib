// tiechui.c

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name("����",({ "tie chan", "chan", "tiechan", "staff"}) );
         set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ�Ѵ�������\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_staff(20);
        setup();
}

