// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "��Ե��" NOR, ({ "kar dan", "dan", "kar" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��԰԰���ɵ�����˵���˿�����ǿ������\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("kar") >= 30)
        {
                message_vision("$N��Ȼ�����ۡ�������һ�ء�\n", me);
                tell_object(me, "���������ǳ��Ŀࡣ\n");
        } else
        {
                tell_object(me, HIG "�㿪ʼ�������������ʼ������������ĸ�Եָ�������ˡ�\n" NOR);
                me->add("kar", 1);
        }

        destruct(this_object());
        return 1;
}

