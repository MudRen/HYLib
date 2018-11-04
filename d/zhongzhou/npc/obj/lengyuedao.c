#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIC "���±���" NOR, ({ "lengyue baodao", "lengyue", "baodao", "dao", "blade" }) );
        set_weight(6200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIC "����һ���������µı�����������������ɭɭ�������ޱȡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIC "$N" HIC "������������µĳ�������ʱֻ��������"
                                 "�ˣ�������ˮ����ת������\n" NOR);
                set("unwield_msg", HIC "$N" HIC "������Х�����ип��������±������"
                                 "���ʡ�\n" NOR);
                //set("stable", 100);
        }
        init_blade(660);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("blade") != "hujia-daofa" ||
            me->query_skill("hujia-daofa", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 12 + 2);
                return HIC "$N" HIC "һ����ȣ��������±���һ�񣬶�ʱ����һ�㲨������"
                       "��$n" HIC "�������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIC "$N" HIC "���������±����ƿջ�������ʱ������ǧ�㵶â������"
                       "���ˣ�$n" HIC "ȫ���ɵ�һ����\n" NOR;
        }
        return damage_bonus;
}
