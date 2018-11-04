#include <weapon.h>
#include <ansi.h>

inherit SWORD;


void create()
{
        set_name(HIR "������" NOR, ({ "kuihua zhen", "kuihua", "zhen", "pin" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR "һ��Ѫ��ɫ��ϸ�룬Ҳ��֪������ʲô�������ɡ�\n" NOR);
                set("value", 8000);
                set("treasure", 1);
                set("material", "silver");
                set("stable", 100);
        }
        init_sword(600+random(320));
        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill("sword") < 250)
                return damage_bonus / 2;


        switch (random(4))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 16 + 2);
                return random(2) ? HIR "ֻ��$N" HIR "��֦�Ͱڣ��ó�������Ӱ��$n"
                                   HIR "�мܶ�ʱɢ�ң���������������\n" NOR:

                                   HIR "$N" HIR "һ����Ц����������һ��������"
                                   "�䣬$n" HIR "��ʱ��������ȫ�����飡\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return random(2) ? HIR "$n" HIR "ֻ����ǰ���Ծ�����������ȣ���"
                                   "���ؿ�һ���ʹ������������Ѫ��\n" NOR:

                                   HIR "$N" HIR "����һ�Σ��Ѳ�������Ӱ��ȴ��$n"
                                   HIR "һ���ҽУ������뾹�������֣�\n" NOR;

        case 2:
                return HIR "$N" HIR "����Ʈ��������һ�غ�â����Ծ����$n"
                       HIR "��ʱֻ���ۻ����ң��޴��мܣ�\n" NOR;

        case 3:
                return HIR "ֻ��$N" HIR "����Ｒ����ǰ��˲������$n" HIR
                       "��ǰ����Ц���������漴Ծ����\n" NOR;
        }
        return damage_bonus;
}
