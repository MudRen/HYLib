// shengzi.c 

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("����", ({ "sheng zi", "sheng" }));
        set_weight(400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������������ʺ�������֮�á�\n");
                set("value", 40);
                set("material", "leather");
                set("wield_msg", "$N��ৡ���һ����������һ��$n����һ���������С�\n");
                set("unwield_msg", "$N�����е�$n�̺ñ������\n");
        }
        init_whip(5);
        setup();
}
