#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIW "��˿��" NOR,({ "rousi suo", "suo", "rousi" }) );
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ���ǳ������ϸ˿�������˿��֯������������֮һ��\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "�ֱ�һ�ӣ���˿���������ߣ����Ѷ�����\n" NOR); 
                set("unwield_msg", HIW "$N�ֱ�һ�ڣ���˿�����Ѿ��ص����У����⽥��ɢȥ�����һƬ�谵��\n" NOR);
                set("stable", 100);
        }
        init_whip(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;


        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("whip") / 10 + 2);
                return HIY "$N" HIY "ŭ��һ����" HIW "��˿��" HIY "��������һ�㣬�����ζ�����"
                       "��$n" HIY "�����������Ӱ֮�¡�\n" NOR;

        case 1:
                n = me->query_skill("whip");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return  HIW "$N" HIW "���������˿��������£�ʱ�����裬ʱ��������������$n" HIW 
                        "���������Ѩ��\n" NOR;

        }
        return damage_bonus;
}
