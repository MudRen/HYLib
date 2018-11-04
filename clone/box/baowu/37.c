#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(NOR + WHT "¹ͷ��" NOR,({ "lutou zhang", "lutou", "zhang" }) );
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT  "һ���ֳ���ľ�ȣ��Ϸ���¹ͷ״��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "wood");
                set("wield_msg", WHT "$N" WHT "������¹ͷ���͵ػ��輸Ȧ��Ȼ���������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "���һ������¹ͷ��ȡ�´��ڵ��ϡ�\n" NOR);
                set("stable", 100);
        }
        init_staff(800+random(320));
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
                victim->start_busy(me->query_skill("staff") / 10 + 2);
                return WHT "$N" WHT "������¹ͷ�Ȼ���÷�������������$n" WHT "���֣�\n" NOR;

        case 1:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIR "$N" HIR "�����������¹ͷ�ȴ�����£�����$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
