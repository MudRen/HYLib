#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIR "������" NOR, ({ "poyang fu", "poyang", "fu", "axe" }) );
        set_weight(26000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "һ�����ɫ�ĵ��ָ����ǳ����أ������߳�һ�ɺ��⡣\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "�ó�һ���޸��������У����˵࣬����������\n" NOR);
                set("unwield_msg", HIR "$N" HIR "����һЦ�������е��������ջر���\n" NOR);
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
                return HIR "$N" HIR "�͵�һ�����ȣ����������񸫾�Ȼ����һ��������$n"
                       HIR "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
