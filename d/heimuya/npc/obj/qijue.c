// weapon: xiuhua.c �廨��
// Jay 4/7/96
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIR"�߾���"NOR, ({ "qijue zhen", "zhen", "qijue" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ϸĥ���߾��롣\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N��Ĵָ��ʳָ���޼����һ��$n��\n");
                set("unwield_msg", "$N�����е�$n����޼䡣\n");
        }
        init_sword(400);
        setup();
}

