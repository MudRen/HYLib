//Cracked by Kafei
// /d/changbai/renshen.c �˲�

inherit ITEM;
#include <ansi.h>
void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
        set_name("�˲�", ({"ren shen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��մ��ɽ��ĳ���ɽ�˲Ρ�\n");
                set("value", 10000);
                set("medicine", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
        if ( (int)me->query_condition("medicine") > 0 ) {
                me->add("eff_jingli", -1);
                me->add("max_jingli", -1);
                message_vision(HIR "$N����һ���˲Σ�ֻ����ͷ�ؽ��ᣬ�������ڣ�ԭ����ʳ̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
                call_out("destroy", 0);
                return 1;
        }

        if( !me->query_temp("cbs/renshen") ) {
                me->add_temp("apply/constitution", 5);
                me->set_temp("cbs/renshen", 1);
        }

        me->add("jingli", 150);
        me->add("neili", 150);

        message_vision(HIG"$N����һ���˲Σ�ֻ���û���һ����������ð������ !\n" NOR, me);

        me->apply_condition("medicine", 
                this_player()->query_condition("medicine")+30);

        call_out("destroy", 0);
        return 1;
}

void destroy()
{
        destruct(this_object());
}

