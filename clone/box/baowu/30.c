#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "���ӽ�" NOR, ({ "junzi jian", "jian", "junzi", "sword" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�\n"
                            "ǫǫ���ӣ���������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "һ����Х��һ���޼��޷�ı�����"
                                 "�������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "��ת���� ��ৡ�����һ������"
                                   "�ӽ���Ȼ���ʡ�\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}
