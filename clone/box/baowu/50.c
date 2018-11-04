#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(NOR + CYN "������" NOR, ({ "tulong dao", "tulong", "dao", "blade" }) );
        set_weight(32000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "����Ǻų���������������������ĳ�����"
                            "�ĵ���������һ�ٶ��֮�ء�\n�ഫ���в��п����Ĵ�"
                            "���ܡ�\n" NOR);
                set("unit", "��");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "һ����Ц���ӱ������Ǳ��ųơ�"
                                 HIR "��������" HIY "�������������߸߾���\n" NOR);
                set("unwield_msg", HIY "$N" HIY "����һЦ��������������ر���\n" NOR);
                set("stable", 100);
        }
        init_blade(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (random(5)==0)
{
        victim->receive_damage("jing", me->query("str") * 2);
        victim->receive_wound("jing", me->query("str") * 2);
        return HIM "�������д��Ŵ̶����ƿ�������һ�������磬��ʱ��$n"
               HIM "ֻ�е��������ҡ�\n" NOR;
}
        return damage_bonus;
}

