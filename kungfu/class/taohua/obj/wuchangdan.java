//wuchangdan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIR"�޳���"NOR, ({"wuchang dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө�����޳��������һ������������ƣ�
����������֮����\n");
                set("value", 0);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        int force_limit, neili_limit, force_skill, add_skill, improve;

        object me = this_player();

        force_limit = me->query_skill("force")*10;
        neili_limit = me->query("max_neili");
        force_skill = me->query_skill("force", 1);

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        fw = (int)me->max_food_capacity();
        me->set("food",fw);
        fw = (int)me->max_water_capacity();
        me->set("water",fw);
        me->set("jing",me->query("max_jing"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_qi",me->query("max_qi"));
        me->set("neili",me->query("max_neili"));
        message_vision(HIR"$N����һ���޳�������ʱȫ�����������\n"NOR,me);
        destruct(this_object());
        return 1;
}
int query_autoload()
{
        return 1;
}
