// da-shugan.c

#include <weapon.h>
 

inherit SWORD;

void create()
{
        set_name("����֦",({ "ku shuzhi", "shuzhi" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "bamboo");
                set("long", "����һ���ɿݵ���֦��\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
           init_sword(15);
        setup();
}
