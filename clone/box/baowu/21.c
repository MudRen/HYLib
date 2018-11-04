#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIW "��������" NOR,({ "jiandun zhusuo", "jiandun", "zhusuo",
                                       "suo", "whip" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ��ͨ�����׵ĳ�������ͷ��ϵ��һ������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "������ȡ��һ������ɫ�ĳ�������ž"
                                 "������ճ����һ�¡�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "΢΢һЦ�������н��������̺ã�"
                                 "�Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(700);
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
                victim->start_busy(me->query_skill("whip") / 10 + 1);
                return HIW "$N" HIW "���н�������һ����������ʱ����һ����â��"
                       "��ͷ����ֱ��$n" HIW "��ǰҪѨ��\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 2 / 3);
                victim->receive_wound("qi", n * 2 / 3);
                return HIW "ֻ��$N" HIW "�������󣬱����á�쬡���һ����������"
                       "����������һ�㣬ֱϮ$n" HIW "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
