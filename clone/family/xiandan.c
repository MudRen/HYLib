// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "�ɵ�" NOR, ({ "xian dan", "dan", "xiandan" }) );
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
        if (me->query("gift/xiandan") >= 5 ||
            me->query("gift/int/succeed") >= 5)
        {
                message_vision("$N��Ȼ�����ۡ�������һ�ء�\n", me);
                tell_object(me, "���������ǳ��Ŀࡣ\n");
        } else
        if (random(5) == 0)
        {
                me->add("gift/int/fail", 1);
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIG "һ�ɻ�����Ȼ����������"
                            "��ͷʹ���ѣ�ǡ�ڴ�ʱһ������֮��"
                            "��Ȼ���𣬶ٸ���̩�ޱȡ�\n");
                me->add("int", 1);
                me->add("gift/int/succeed", 1);
        }

        if (me->query("gift/xiandan") < 5)
                me->add("gift/xiandan", 1);
        destruct(this_object());
        return 1;
}

