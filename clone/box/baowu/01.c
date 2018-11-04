#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(NOR + YEL "�Ͻ���Ե�" NOR,({ "bagua dao", "bagua", "dao", "blade" }) );
        set_weight(4600);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", YEL "����һ���񱳱��У��Ͻ������İ��Ե���������"
                            "����һ�����̡��֡�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", YEL "$N" YEL "һ����Х����ৡ���һ�������"
                                 "����Ե����������������ɷΪ���档\n" NOR);
                set("unwield_msg", YEL "$N" YEL "���һ�����������Ͻ���Ե�"
                                   "��ر���\n" NOR);
                set("stable", 100);
}
        init_blade(500+random(320));
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
                return YEL "$N" YEL "һ����ȣ������Ͻ���Ե����հ��Է�λ��"
                       "��ն��������һ������â���Ƶ�$n" YEL "�������ˣ�\n"
                       NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return YEL "$N" YEL "�����Ͻ���Ե����հ��Է�λ����ն����$n"
                       YEL "�ټ���Χ��Ӱ�������Լ���£�����ѵֵ���\n" NOR;
        }
        return damage_bonus;
}
