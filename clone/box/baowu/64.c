#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIR "�������" NOR,({ "ruanhong zhusuo", "ruanhong",
                                       "zhusuo", "suo", "whip" }) );
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "һ֧ͨ��Ѫ��ĳ���������ȥ���Ǽ��͡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "������ȡ��һ��Ѫ��ɫ�ĳ�������ž"
                                 "������ճ����һ�¡�\n" NOR);
                set("unwield_msg", HIR "$N" HIR "һ����ߣ���������������̺ã�"
                                 "�Ż����䡣\n" NOR);
                set("stable", 100);
        }
        init_whip(300+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 10 + 2);
                return HIR "$N" HIR "���������������ת��������������Ӱ����"
                       "��$n" HIR "�ۻ����ң����ֲ�����\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIR "$N" HIR "һ���ߺȣ����������������ת������ʱѪ��"
                       "���죬��Ӱ�ݺᣬ�����ƻã�����$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
