#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(NOR + WHT "��������" NOR,({ "xuantie qipan", "xuantie", "qipan", "pan" }) );
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "һ������������̣��������������ۡ��������ио��ǳ��ĳ�\n"
                            "�أ���ϸһ�����������̾�Ȼ�����������ɡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "�ӱ���ȡ��һ������������̸߾������У���"
                                 "ʱ�����о�����һ������\n" NOR);
                set("unwield_msg", WHT "$N" WHT "����һЦ�������е����������ջء�\n" NOR);
                set("stable", 100);
        }
        init_hammer(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(16))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("hammer") / 10 + 2);
                return WHT "$N" WHT "��ǰһ������������������Ϸ����̷�һ�����裬$n" WHT "ֻ"
                       "�����ۻ����ң���������η�壡\n" NOR;

        case 1:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return WHT "$N" WHT "�͵�һ�����ȣ������������̾�Ȼ����һ��������$n" WHT "��"
                       "ȥ��\n" NOR;
        }
        return damage_bonus;
}
