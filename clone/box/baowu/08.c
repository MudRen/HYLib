#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(NOR + GRN "������" NOR, ({"lvyu dongxiao", "lvyu", "dongxiao", "xiao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", GRN "һ֧�������ɵĶ������ȥ��Ө��������"
                            "���˾�������������\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "stone");
                set("wield_msg", GRN "$N" GRN "����һ�ӣ������Ѷ���һ֧��Ө�������������\n" NOR);
                set("unwield_msg", GRN "$N" GRN "����������һת��գ�ۼ���Ȼ����Ӱ�١�\n" NOR);
                set("stable", 500+random(320));
        }
        init_sword(100);
        setup();
}
