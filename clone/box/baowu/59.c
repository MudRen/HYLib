#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW "����" NOR, ({ "yu xiao", "yu", "xiao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", HIW "һ֧�������ɵ��������ȥ��Ө�����������˾������������\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "stone");
                set("wield_msg", HIW "$N" HIW "����һ�ӣ������Ѷ���һ֧��Ө��������\n" NOR);
                set("unwield_msg", HIW "$N" HIW "��������һת��գ�ۼ�������Ȼ����Ӱ�١�\n" NOR);
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
                return HIW "ͻȻ��һ������������$N" HIW "��������$n" HIW
                       "��ʱֻ����̫��Ѩ������ʹ��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("jing", n / 3);
                victim->receive_wound("jing", n / 3);
                return HIW "$N" HIW "������������ʽ����������������$n" HIW
                       "��ʱֻ����Ѫ��ӿ������֮����\n" NOR;
        }
        return damage_bonus;
}
