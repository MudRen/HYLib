// blade.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���Ľ�", ({ "xixiajian" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "iron");
                set("long", "������΢�е㳤�����Ľ�����������Լʮ���ء�\n");
                set("wield_msg", "$N���һ�����Ľ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������䡣\n");
        }
        init_sword(35);
        setup();
}
