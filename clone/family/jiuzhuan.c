// jiuzhuan.c ��ת��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY "��ת��" NOR, ({ "jiuzhuan jindan", "dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ž�ɫ���ɵ�����˵��̫���Ͼ�"
                            "�����������鵤��ҩ��\n");
                set("value", 150000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        int effect;

/*
        log_file("static/using", sprintf("%s(%s) eat ��ת�� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));
*/

        effect = 0;
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("gift/int/succeed") < 4 && random(2))
        {
                effect++;
                write(HIM "������Լ���ͷ�Ը������ˡ�\n" NOR);
                me->add("gift/xiandan", 1);
                me->add("gift/int/succeed", 1);
                me->add("int", 1);
        }

        if (me->query("gift/dex/succeed") < 4 && random(2))
        {
                effect++;
                write(HIR "������Լ����ȽŸ�����ˡ�\n" NOR);
                me->add("gift/unknowdan", 1);
                me->add("dex", 1);
                me->add("gift/dex/succeed", 1);
        }

        if (me->query("gift/con/succeed") < 4 && random(2))
        {
                effect++;
                write(HIC "������Լ�����Ϣ��ͨ���ˡ�\n" NOR);
                me->add("gift/xisuidan", 1);
                me->add("con", 1);
                me->add("gift/con/succeed", 1);
        }

        if (me->query("gift/str/succeed") < 4 && random(2))
        {
                effect++;
                write(HIG "������Լ���������ǿ���ˡ�\n" NOR);
                me->add("gift/shenliwan", 1);
                me->add("str", 1);
                me->add("gift/str/succeed", 1);
        }

        write(HIM "ڤڤ������������ֻ������̨һƬ�����������ޱȡ�\n" NOR);
        me->add("magic_points", 1000 + random(1000));

        destruct(this_object());
        return 1;
}



