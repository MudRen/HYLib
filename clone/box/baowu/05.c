#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "��������" NOR, ({ "canyang baojian", "canyang", 
                                        "sword" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "
�˽�����ߣ�ϸ������ͨ�巺����⡣�����������Ͽ̲���ͼ
�ƣ�����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", CYN "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", CYN "$N" CYN "һ����ߣ������е�"
                                   "�����������뽣�ʡ�\n" NOR);

                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n = me->query_skill("sword");

        if (me->query_skill("sword") < 150)
                return damage_bonus / 2;


        switch (random(4))
        {
        case 0:
                victim->receive_damage("jing", n / 2 );
                victim->receive_wound("jing", n / 4);
                return HIW "$N" HIW "��Хһ��������" HIY "��������" HIW 
                           "������ǰ���͵ػӳ���һ����ȵĽ�����$n" 
                           HIW "�Ƶ��������ˡ�\n" NOR;
        case 1:
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIR "$N" HIR "����" HIY "��������" HIR "ͻȻ����"
                           "һ����ҫ�۶�Ŀ��һ�����ȵĽ�������$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
