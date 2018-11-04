#include <weapon.h>
#include <ansi.h>

inherit BLADE;



void create()
{
        set_name(GRN "�̲���¶��" NOR, ({ "xianglu dao", "lvbo", "xianglu", "dao" }));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", GRN "һ������ɫ�Ĺ�ͷ��������ɢ����һ���ȳ�����"
                            "�����˼�����Ż��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("unwield_msg", GRN "$N" GRN "Ĩ��Ĩ�������������յ��̲�"
                            "��¶���ջء�\n" NOR);
                set("stable", 100);
        }
        init_blade(680);
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("blade") < 150)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 10 + 2);
                return GRN "$N" GRN "�̲���¶��������ն������һ������â��$n"
                       GRN "ֻ��һ�������˱Ƕ��������Ҵ��⣬��\n�����������"
                       "�мܶ�ʱɢ�ҡ�\n" NOR;
        case 1:
                n = me->query_skill("blade");
        victim->receive_damage("jing", me->query("str") );
        victim->receive_wound("jing", me->query("str") );
                return GRN "$N" GRN "�̲���¶��������ն������һ������â��$n"
                       GRN "ֻ��һ�������˱Ƕ�����΢һ���죬��\nʱ����������"
                       "������\n" NOR;
        }
        return damage_bonus;
}

