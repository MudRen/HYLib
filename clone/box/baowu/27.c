#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(NOR + WHT "�Ż�����" NOR, ({ "jiuhuan xizhang", "jiuhuan",
                                              "xizhang", "zhang" }) );
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ��ͨ����ڵ����ȣ����ּ�Ϊ��"
                            "�أ��ǳ����ͣ�������\n�������ഫ��ʥ�����"
                            "��ͭ��������������Ž�������פ�ա�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "ȡ���Ż������������У���ʱ"
                                 "�𲨵����������߷�����\n" NOR);
                set("unwield_msg", HIW "$N" WHT "΢΢һЦ�������еľŻ���"
                                 "�ȷŻذ��ҡ�\n" NOR);
                set("stable", 100);
        }
        init_staff(700+random(320));
        setup();
}
