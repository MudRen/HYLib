#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����", ({"roujing sword", "sword", "jian"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "iron");
                set("long", "һ��ϸ���Ľ�,���Ű��ڵĹ⡣\n");
                set("wield_msg", "$N���һ��ϸ����$n�������С�\n");
                set("unequip_msg", "$Nһ���ֽ����е�$n���볤��֮�С�\n");
        }
        init_sword(150);
        setup();
}

