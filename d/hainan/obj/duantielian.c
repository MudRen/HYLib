// blade.c

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("�Ͽ�������", ({"duan tielian", "lian", "whip"}));
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ���������������������ֺ�ã��\n");
                set("unit", "��");
                set("value", 500);
        }
        init_whip(125);
        setup();
}

