#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "���齣" NOR, ({ "huanling jian", "huanling", "sword" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "��������ϸ����ɢ���ŵ������⡣\n" NOR);
                set("unit", "��");
                set("value", 7000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "���⻮�������齣������$N" HIW "���С�\n" NOR);

                set("unwield_msg", HIW "��غ�����$N" HIW "���еĻ��齣����Ȼ��û ��\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;


        if (random(5) == 1)
        {
               n = me->query_skill("sword");
               victim->receive_damage("qi", n * 3 / 5);
               victim->receive_wound("qi", n * 2 / 7);
               return HIW "$N" HIW "һ����ߣ����л��齣��������һ�����߲�������ʱһ�����������⼤"
                      "�����������$n" HIW "��\n" NOR;
        }
        return damage_bonus;
}
