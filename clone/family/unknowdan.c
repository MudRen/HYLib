// unknow.c δ���ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "����ɵ�" NOR, ({ "huohong xiandan", "dan", "xiandan" }));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��԰԰�Ļ���ɵ�����֪����ʲô�ô���\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/unknowdan") >= 5 ||
            me->query("gift/dex/succeed") >= 5)
        {
                message_vision("$Nҡҡ�λεģ�ͻȻ��žડ�һ����ˤ�˸���ͷ��\n", me);
                tell_object(me, "����ó����Ժ�ͷ�ؽ���ġ�\n");
        } else
        if (random(5) == 0)
        {
                me->add("gift/dex/fail", 1);
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIM "��ʱ��������ȹ����ѣ�һʱ��ʹ��"
                            "�̣����˹�ȥ��\n" NOR);
                me->add("dex", 1);
                me->add("gift/dex/succeed", 1);
                me->unconcious();
        }

        if (me->query("gift/unknowdan") < 5)
                me->add("gift/unknowdan", 1);
        destruct(this_object());
        return 1;
}

