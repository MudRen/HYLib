#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(WHT "���ٽ�" NOR,({ "tieqin jian", "tieqin", "jian", "qin" }) );
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ�ߵ��й��ӻ��Ƶ����٣����ٵ�һ��¶��һ��������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "�����ӻ������ٵ��ټ������һ����"
                                 "���еĳ����������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "΢΢һЦ�������е����ٽ��ջأ���"
                                 "��������ȥ��\n" NOR);
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;



        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 12 + 2);
                return WHT "$N" WHT "һ���Ϻȣ�������Ȼ�����������٣����ٶ�ʱ����һ�ɼ����"
                       "������$n" WHT "ֻ��ͷ��Ŀѣ���������ʣ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return WHT "$N" WHT "һ����ߣ��������ٽ�һ����ʱ��������һ������Я�ż�"
                       "�������ֱ��$n" WHT "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
