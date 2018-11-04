#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "�����з�" NOR, ({ "zhenyue shangfang", "zhenyue", 
                                              "shangfang", "sword" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "
�˽������������λ��ʮһ���Զ���������磬���彣����Ͷ
��������Ի�����з�������׭�飬�������ͨ�����⡣������
����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", CYN "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", CYN "$N" CYN "һ����ߣ������е�"
                                   "�����з��������뽣�ʡ�\n" NOR);

                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n = me->query_skill("sword");



        switch (random(14))
        {
        case 0:
                victim->receive_damage("jing", n / 2);
                victim->receive_wound("jing", n / 4);
                return HIW "$N" HIW "����������" NOR + CYN "��"
                       "���з�" HIW "������ʱ��â���ǣ��Ƶ�$n"
                       HIW "�������ˣ�\n" NOR;
        case 1:
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIR "$N" HIR "����" NOR + CYN "�����з�"
                       HIR "��⵴����͸��һ��������Ľ���ֱ��$n"
                       HIR "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
