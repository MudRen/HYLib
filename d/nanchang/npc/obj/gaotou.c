
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("��ͷ", ({"gao tou", "tou","gao"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѹ䣬���������ɿ�ʯ�ġ�\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(500);
        setup();
}

