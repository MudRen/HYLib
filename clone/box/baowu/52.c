#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "�����ؽ�" NOR, ({ "xuantie jian", "xuantie", "jian" }) );
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "һ�����������ɵ��޷泤�������ֳ����ޱȣ�����ȴ�̲��ż����������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", NOR + WHT "$N" NOR + WHT "���$n" NOR + WHT"���̽��������������ݣ�������Ȼ�𾴡�\n" NOR);
                set("unwield_msg", NOR + WHT "$N" NOR + WHT "���쳤̾��Ǳ����������$n" NOR + WHT "�ջء�\n" NOR);
                set("stable", 100);

        }
        init_sword(600+random(320));
        setup();
}

