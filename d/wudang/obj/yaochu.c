// yaochu.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("ҩ��", ({ "yao chu", "chu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ��ҩ�õĳ�ͷ��\n");
                set("value", 30);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_blade(4);
        setup();
}
