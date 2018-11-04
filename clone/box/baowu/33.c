#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "������" NOR,({ "liangji jian", "liangji", "jian", "sword" }) );
        set_weight(6500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ�������ĳ����������з֣�һ��ʻ��ɫ����"
                                "һ��ȴ���纮ѩ��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "һ����̾�����һ���������"
                                 "�����������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "һ����ߣ������е���������"
                                 "�ر���\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("sword") < 160)
                return damage_bonus / 2;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 14 + 2);
                return HIW "$N" HIW "��ת�������������������������ʱ����͸"
                       "��������â��ֱ�Ƶ�$n" HIW "�������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIR "$N" HIR "�����������й�ֱ���������̳��������ʱ"
                       "͸��һ�����ȵĽ�����ֱӿ$n" HIR "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
