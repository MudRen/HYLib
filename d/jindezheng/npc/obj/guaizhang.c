
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("��ͷ����", ({"guai zhang", "zhang", "staff"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
                set("material", "wood");
                set("long", "����ľ�����Ĺ���,һ�˳������Σ�\n");
                set("wield_msg", "$N����һ��$n�������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_staff(120);
        setup();
}

