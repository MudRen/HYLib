// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�ɹŵ�", ({ "menggublade" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("material", "iron");
                set("long", "������΢�е�����ɹŵ�����������Լʮ���ء�\n");
                set("wield_msg", "$N���һ���ɹŵ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������䡣\n");
        }
        init_blade(35);
        setup();
}
