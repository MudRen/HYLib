// shenliwan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({ "shenli wan", "wan"}) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ԲԲ�������裬��˵���˿�����ǿ������\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/shenliwan") >= 5 ||
	    me->query("gift/str/succeed") >= 5)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
        if (random(5) == 0)
        {
                me->add("gift/str/fail", 1);
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIR "�����˫�ۼ������ѣ�������������\n" NOR);
                me->add("str", 1);
                me->add("gift/str/succeed", 1);
        }

        if (me->query("gift/shenliwan") < 5)
                me->add("gift/shenliwan", 1);
        destruct(this_object());
        return 1;
}

