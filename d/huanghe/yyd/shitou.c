// shitou.c ʯͷ
// zly 1999.07.27
 
inherit ROOM;

#include <ansi.h>
#include <room.h>

int do_jump(string arg);
int do_tao(string arg);
 
void create() 
{ 
        set("short", "ʯͷ");
        set("long", @LONG
����һ��խС����Ŵ������ݵü�������š����Ϸ������и�С
��(dong)���������������ֽ�ȥ��
LONG
        );
        set("exits", ([ 
]));

        setup();
}

void init()
{
        
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_tao", "tao");
        add_action("do_tao", "draw");
}

int do_jump(string arg)
{
        object me = this_player();
        if (arg == "chi") {
                if (me->query_skill("dodge", 1) >= 120) {
                        message("vision", me->name() + "���˿��������������Ծȥ��\n",
                                environment(me), ({me}) );
                        write("�����˿��������������Ծȥ��\n");
                        me->move(__DIR__"houyuan");
                        message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n",
                                environment(me), ({me}) );
                        
                        return 1;
                }
                else {
                        message("vision", me->name() + "���������Ծȥ��ֻ������ͨ��һ����" + me->name() + "ˤ����У��Ǳ������˻�����\n",
                                environment(me), ({me}) );
                        write("�����������Ծȥ��ֻ������ͨ��һ������ˤ����У��Ǳ������˻�����\n");
                        me->receive_damage("qi",80);
                        return 1;
                }
        }
        return 0;
}

int do_tao(string arg)
{
        object me = this_player();
        object ob;
        if (arg == "dong") {
                if ( me->query_temp("tao_times") < 15 )
        {
                message_vision("$N����һ����һ���ʯͷ�ϵ���������\n", me);
                me->set_temp("tao_times", random(35));
                me->unconcious();
                return 1;
        }
                if ( !me->query_temp("tao") )
        {
                message_vision("$N�ڶ������˰��죬ʲôҲû��������\n", me);
                return 1;
        }
        else {
                message_vision("$N�ڶ�����ϸ�������š�\n", me);
                ob=new(__DIR__"obj/yaoshi");
                ob->move(this_player());
                tell_object(me, RED"��ֻ���ּ�һ��������һ�����Ķ�������Ͻ��������˳�����\n"NOR);
                me->set_temp("tao_times", 1);
                me->delete_temp("tao");
                return 1;
            }
      }
     return 0;
}
