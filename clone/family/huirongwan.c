// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({ "huirong wan", "wan", "huirong" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��԰԰�ĵ��裬��˵���˿��Ա��Խ��Խ���治֪��˭��Ҫ�������Ү��\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("per") <= 13)
        {
                message_vision("$N��Ȼ�����ۡ�������һ�ء�\n", me);
                tell_object(me, "���������ǳ��Ŀࡣ\n");
        } else
        {
                tell_object(me, HIG "�㿪ʼ���������ò��ʼ�ı䣬����ѿ����ˡ�\n" NOR);
                me->add("per", -1);
        }

        destruct(this_object());
        return 1;
}

