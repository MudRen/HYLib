#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "���콣" NOR, ({ "yitian jian", "yitian", "jian", "sword" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "�������������������������Ƶ����콣��\n"
                            "�ഫ���в��п����Ĵ����ܡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "ֻ����ಡ���һ���ƿ����죬�ų����µ�һ"
                             "��������콣�ѱ�$N" HIW "�������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "�����콣������䣬����ֽ���"
                             "�ų���â��\n"NOR);
                set("stable", 100);
        }
        init_sword(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (random(5)==0)
{
        victim->receive_damage("qi", me->query("str") * 5);
        victim->receive_wound("qi", me->query("str") * 4);
        return WHT "���콣Я�Ŵ̹Ƿ���������ʣ�$n"
               WHT "ֻ��ȫ��������һ˿˿���Ž���ӿ����\n" NOR;
}
        return damage_bonus;
}

