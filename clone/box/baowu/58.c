#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(NOR + WHT "�㳦��" NOR, ({"yuchang jian", "yuchang", "jian", "dagger"}));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", WHT "һ�����ӳ��صĶ�ذ�ף�ذ���Ͽ��С�" HIY "�㳦"
                            NOR + WHT "�����֡�\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "�Ӷ����ͳ�һ��ذ�ף������ж�ʱ��"
                                 "��һ˿������\n" NOR);
                set("unwield_msg", WHT "$N" WHT "���е��㳦��һת��գ�ۼ���Ȼ��"
                                 "��Ӱ�١�\n" NOR);
                set("stable", 100);
        }
        init_dagger(600+random(320));
        setup();
}
