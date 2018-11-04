#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "������" NOR, ({ "bailong jian", "bailong", "jian" }) );
        set_weight(5500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "��泤Լ���ߣ��������ƹ��ӣ����������������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "�ӱ���ৡ��ĳ��һ��������"
                                 "�������������������ԡ�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "�����а������������������"
                                 "�ؽ��ʡ�\n" NOR);
                set("stable", 100);
        }
        init_sword(500+random(320));
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
                return HIW "$N" HIW "�����а�����бб����������Ȼ����һ��"
                       "�׹⣬��$n" HIW "�Ƶ��������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIW "$N" HIW "һ����Х�����а�����������ߡ��˸�����"
                       "���ͷ�����$n" HIW "���������\n" NOR;
        }
        return damage_bonus;
}
