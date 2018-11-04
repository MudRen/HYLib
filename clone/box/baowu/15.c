#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIR "���α�" NOR,({ "hexing bi", "hexing", "bi" }) );
        set_weight(800);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "һ֧ͨ���ɫ��ë�ʣ��ʺ��Σ�����ȥ�Ǽ�������\n" NOR);
                set("unit", "֧");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "������ȡ��һ֧���α��������С�\n" NOR);
                set("unwield_msg", HIR "$N" HIR "һ����ߣ������к��αʷŻ����䡣\n" NOR);
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
                return HIR "$N" HIR "���к��αʼ���ת������$n" HIR "����Χס��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 5);
                victim->receive_wound("qi", n * 3 / 5);
                return HIR "$N" HIR "һ��ŭ�ȣ����к��α��͵���������$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
