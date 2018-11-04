#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "ī��" NOR, ({ "mo jian", "mo", "jian" }) );
        set_weight(14000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ��ͨ��ī�ڵĳ���������͸������Ĺ���\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "ֻ��$N" WHT "��������һ���������Ѷ���һ��ͨ"
                                 "��ī�ڵĳ�����\n" NOR);
                set("unwield_msg", WHT "$N" WHT "΢΢һЦ�������е�ī�ڳ��������"
                                 "�䡣\n" NOR);
                set("stable", 100);
        }
        init_sword(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 12 + 1);
                return WHT "$N" WHT "��תī�����������������佣������ʱ�������䣬����$n"
                       WHT "���ֲ�����\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return WHT "$N" WHT "һ����ߣ�����ī���й�ֱ������ʱһ��������ī�������"
                       "�����������$n" WHT "��\n" NOR;
        }
        return damage_bonus;
}
