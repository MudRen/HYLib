#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
        set_name(HIG "�Ϻ���ľ" NOR, ({ "nanhai shenmu", "nanhai", "shenmu", "club" }) );
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "������̰�ؽ��ݵ�ľ����������ͨ��ȴ��������һ�㣬��Ӳ�ޱȡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�ó�һ��������̰�ؽ��ݵ�ľ���������С�\n" NOR);
                set("unwield_msg", HIG "$N" HIG "�����е��Ϻ���ľ�����Ȧ�ӣ���ر��ϡ�\n" NOR);
                set("stable", 100);
        }
        init_club(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;



        switch (random(8))
        {
        case 0:
                n = me->query_skill("club");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "$N" HIG "�粽��ǰ�������Ϻ���ľת�����֣�������磬�Ӷ�"
                       "������$n" HIG "ɨȥ��\n" NOR;
        }
        return damage_bonus;
}
