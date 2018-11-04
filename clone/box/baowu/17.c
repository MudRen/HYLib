#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
        set_name(NOR + YEL "�ƽ�" NOR, ({"huangjin fu", "huangjin", "fu"}));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "����һ�����������Ĵ󸫣�����ĩ���ƺ���Щ�ɶ���\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "gold");
                set("wield_msg", YEL "$N" YEL "����һ�����������Ĵ󸫣����ֻ��������¡�\n" NOR);
                set("unwield_msg", YEL "$N" YEL "����һЦ�������еĻƽ��ջر���\n" NOR);
                set("stable", 100);
        }
        init_hammer(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;



        switch (random(6))
        {
        case 0:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return YEL "$N" YEL "һ���Ϻȣ����лƽ���ʱ��â���ǣ�����һ����$n"
                       YEL "������ȥ��\n" NOR;
        }
        return damage_bonus;
}
