#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(NOR + WHT "����" NOR, ({  "hei suo", "hei", "suo", "whip" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ����ڵĳ��ޣ��������ۣ���������"
                            "���أ���\n��ʧ���ͣ�ʵ����ǧ������֮�\n" NOR);
                set("long", WHT "һ֧ͨ����ڵĳ��ޣ�����ȥ���Ǻܼ��͡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "һ���֣�������Ϣ�Ľ������������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "�����еĺ������𣬷Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(600+random(320));
        setup();
}
