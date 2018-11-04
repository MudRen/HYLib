// /clone/drug/badan.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");

}

void create()
{
        set_name(HIR"�����˵�"NOR, ({"xuming badan", "dan"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("medicine", "drug");
		set("make/drug", 1);
        }
	setup();
}

int do_eat(string arg)
{
       
        object me = this_player();
        if (!living(me)) return notify_fail("�뵱����\n");
        if (!id(arg)) return 0;
        if( !environment(me)->query("bwdhpk"))
{
       message_vision(HIR "\n$N��ҩ Ϊ����ר�ã�ҩ��û���ˣ�\n\n" NOR,
                       me);
	destruct(this_object());   
       return 1;       
}

        message_vision("$N��������ĳ���һ��"
        +this_object()->query("name")+
        "�����ڰ������˻�����\n"
        ,me);
        me->reincarnate();
        me->set("qi", me->query("max_qi"));
        me->set("jing", me->query("max_jing"));
        destruct(this_object());
        return 1;
}
