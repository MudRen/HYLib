#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIW "����" NOR + HIY "����" NOR,({ "yinsuo jinling", "suo", "ling",
                                                    "yinsuo", "jinling" }) );
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ����ɫ�ĳ��������������Ž����Ĺ�"
                            "�󣬿���ȥ���Ǽ��͡�������һ��ϵ������"
                            "���塣\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "����Ĵӻ���ȡ��һ��"
                                 "��ɫ�ĳ����������С�\n" NOR); 
                set("unwield_msg", HIW "$N����������" NOR + HIY "��"
                                 "��" NOR + HIW "�����䣬����ֽ���"
                                 "�ų���â��\n" NOR);
                set("stable", 50);
        }
        init_whip(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 10 + 2);
                return HIY "$N" HIY "һ�����ȣ����е�" NOR + HIW "����"
                       NOR + HIY "����ó������Ӱ��ֱ��$n" HIY "��ȥ��"
                       HIR "\n$n" HIR "��һ���ɣ�ֻ��ȫ��һ�飬�ѱ�$N"
                       HIR "���е���ҪѨ��\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return  HIY "$N" HIY "һ����Х������" NOR + HIW "����"
                        NOR + HIY "������������ͨ�죬����ǵ�Ϯ��$n"
                        HIY "��\n" NOR;
        }
        return damage_bonus;
}

