#include <weapon.h>
#include <ansi.h>

inherit SWORD;



void create()
{
        set_name(HIY "���佣" NOR,({ "zhenwu jian", "jian", "sword", "zhenwu" }) );
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
����һ�����������ı����������䵱�����˳ִ˽�������ħ��ɨ��Ⱥ��
������С�����˽��޲��ĵ���ҡ��
LONG );
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(4))
        {
        case 0:
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIC "$N" HIC "��ǰһ�������е�" NOR + HIY "���佣" NOR
                       + HIC "�û�������ԲȦ����$n" HIC "��ȥ������ϸ��֮����"
                       "$n" HIC "���һ\n������֪��εֵ���ֻ���������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sowrd");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                n = victim->query("eff_jing");
                n /= 2;
                victim->receive_damage("jing", n);
                victim->receive_wound("jing", n / 2);
                return random(2) ? HIY "$N" HIY "һ�����������е����佣����һ"
                                   "�����磬��ৡ���ɨ��$n" HIY "��ȥ��\n" NOR:
                                   HIY "$N" HIY "ͻȻ�����ȵ�����аħ�������"
                                   "�����������������佣" HIY "����һ����$n"
                                   HIY "��ʱ�����ۻ����ң�\n" NOR;
        }

        // double effect
        return damage_bonus;
}


