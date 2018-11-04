#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(WHT "��������" NOR, ({ "chuangwang jundao", "chuangwang", "jundao", "dao", "blade" }) );
        set_weight(6200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "���Ǵ�����ʹ�ù��ĵ���������м���С�֡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", WHT "$N" WHT "������Ц����������һ����Ϊ�žɵ��䵶��\n" NOR);
                set("unwield_msg", WHT "$N" WHT "�������ܣ���̾һ��������������������䡣\n" NOR);
                set("stable", 100);
        }
        init_blade(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;



        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 12 + 2);
                return WHT "$N" WHT "һ��ŭ�ȣ����д�����������������������������ʱ��$n"
                       WHT "����������\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n / 2);
                victim->receive_wound("qi", n / 2);
                return WHT "$N" WHT "��ת���д��������������ʱ���ճ�һ�������ľ�â��ֱ"
                       "ӿ$n" WHT "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
