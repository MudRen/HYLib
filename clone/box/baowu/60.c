#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG "������" NOR, ({ "yuzhu zhang", "yuzhu", "zhang" }));
        set_weight(26000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "����һ���������Ƶ��ȣ�����ؤ��������"
                            "���İ������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�ӱ�����һ����������"
                                 "�����ȣ�������˸�Ȧ�ӡ�\n" NOR);
                set("unwield_msg", HIG "$N" HIG "΢΢һЦ�������е���"
                                 "���Ȳ�ر���\n" NOR);
                set("stable", 100);
        }
        init_staff(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(6))
        {
        case 0:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "$N" HIG "������������һ�񣬵�ʱ�ó������Ӱ�����$n"
                       HIG "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
