#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + YEL "ʥ����" NOR, ({ "shenghuo ling", "shenghuo", "ling" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 8000);
                set("material", "steel");
                set("treasure", 1);
                set("long", NOR + YEL "
����һ�����������ĺ��ƣ�����ȥ�ǽ���������ʵ�ȴ�Ǽ�Ӳ
�ޱȡ��������ƾ�����͸���������������л�����ڣ�ʵ����
����ӳ�⣬��ɫ��á����Ͽ̵��в��ٲ�˹�ģ������ƺ�����
ѧ�йأ�������£�������Ҫ��ϸ�ж�һ�����ܹ�����\n" NOR);
                set("wield_msg", HIR "$N" HIR "��������һƬ�����"
                                 "�����������С�\n" NOR);
                set("unwield_msg", HIR "$N" HIR "����һ�����ѽ�ʥ��"
                                 "���������䡣\n" NOR);

        }
        init_sword(800+random(320));
        setup();
}
