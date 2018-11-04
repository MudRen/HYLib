// xiaobao.c С��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "С��" NOR, ({ "xiao bao", "bao", "xiaobao" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ž�Ӳӵĵ�ҩ����˵������Ѫ���ա�\n");
                set("value", 20000);
                set("unit", "��");
                set("per",5);
                set("time",864000);
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        if (me->query("have_meirong_dan"))
        {
                tell_object(me, "���Ѿ����ù����Ƶ�ҩƷ��ҩ����δ��ʧ�������˼������ã�\n");
                return 1;
        }
        
        log_file("static/using", sprintf("%s(%s) eat С�� at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        message("vision", "���ƺ��о�" + me->name() + "�����ݽ���ģ����������������һ������\n",
                          environment(me), ({ me }));

        tell_object(me, HIY "�������Ƥ���������ƺ�Ҫ���ѿ�����"
                        "����һ�����ͣ�������������������ɺܶࡣ\n" NOR);

        me->set("have_meirong_dan", this_object()->query("per"));
        me->set("meirong_time", time() + this_object()->query("time"));
        me->add_temp("apply/per", this_object()->query("per"));
        me->set_temp("meirong_dan_used",1);
        
        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; } 

