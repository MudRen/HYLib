#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG "������" NOR, ({ "wuming jian", "wuming", "jian" }) );
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "�˽���Լ�ĳߣ��������������������\n�˽�ħ�����������ʱ���֡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" NOR + WHT "���$n" NOR + WHT"�����ֶ�����һ����ʦ�緶��\n" NOR);
                set("unwield_msg", HIG "$N" NOR + WHT "��Хһ������ָ�䣬��$n" NOR + WHT "�ջء�\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}
