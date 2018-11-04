#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(HIW "��������" NOR,({ "baiyu yaoqin", "baiyu", "yaoqin", "qin" }) );
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ��ͨ�嶼���ϵȰ�����ƶ������٣��ǳ��Ļ���������\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "�ӱ��󻺻�ȡ��һ�߰������٣������"
                                 "�ϱ������С�\n" NOR);
                set("unwield_msg", HIW "$N" HIW "΢΢һЦ�������еİ�������������"
                                 "�����ŵ�����\n" NOR);
                set("stable", 100);
        }
        init_sword(620);
        setup();
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIW "$N" HIW "���һ�������о���һ�����������ɶ�ʱһ�䣬$n" HIW "��"
                       "ʱ����ͷ��Ŀѣ���޷���ս��\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIW "$N" HIW "һ����ߣ����ַ�����������������ʱ������ü����ޱȣ�"
                       "��������һ������$n" HIW "��\n" NOR;
        }
        return damage_bonus;
}
