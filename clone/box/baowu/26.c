#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "���ڹ�" NOR,({ "jinwu gou", "gou", "jinwu", "jin" }) );
        set_weight(3500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "һ����������Ĺ��ӣ����Ƿ��������˺���һֻ"
                            "��ͷ��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "��Цһ�����ӱ�����һ������"
                                 "��״�Ľ��������£���ʱ��â���䡣\n" NOR);
                set("unwield_msg", HIY "$N" HIY "һ����ߣ������н��ڹ����"
                                 "����\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;



        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIY "$N" HIY "�����н��ڹ������ն����������һ������"
                       "�Ľ�â��ֱ�Ƶ�$n" HIY "�������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIY "$N" HIY "һ����Х�����γ���������н��ڹ����"
                       "���䣬����$n" HIY "ȫ�����ҪѨ��\n" NOR;
        }
        return damage_bonus;
}
