#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "��Ů��" NOR, ({ "shunv jian", "jian", "shunv", "sword" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�\n"
                            "����Ů�����Ӻ��ϡ�\n" NOR);
                set("unit", "��");
                set("value", 6000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "һ����Х��һ���޼��޷�ı�����"
                                 "�������С�\n" NOR);

                set("unwield_msg", HIW "$N" HIW "��ת������ৡ���һ������"
                                   "Ů�������ʡ�\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(600+random(320));
        setup();
}
