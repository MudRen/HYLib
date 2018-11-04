// ��Ժ houyuan.c
// zly 1999.06.10
 
inherit ROOM; 

void close_gate();
int do_jump(string arg);
int do_unlock(string arg);

void create() 
{ 
        set("short", "��Ժ");
        set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ��(chi)����������һ��޴��ޱ�
�ļ�ɽ����ɽ���������һ�������ŵĵط���ˮ�ص����������˸�
�ָ����Ļ��ݡ������������Ĵ�������������и�С��(door)��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ 
            "south" : __DIR__"dating",
]));

        set("item_desc", ([
            "chi" : "������һЩ��ҶƯ�����档\n",
            "door" : "����һ�����ţ��ź������ţ�����ͨ���ɽ�ıؾ�֮·��\n",
        ]));

        set("objects", ([
         __DIR__"npc/xiaoyaozi":1,
         __DIR__"npc/changcf":1,
         __DIR__"npc/huajy":1,
         __DIR__"npc/gaiyiming":1,
        ]));

        setup();
}

void init()
{
        
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
        add_action("do_unlock", "unlock");
        add_action("do_unlock", "kai");
}

int do_jump(string arg)
{
        object me = this_player();
        if (arg == "chi") {
                if (me->query_skill("dodge", 1) >= 120) {
                        message("vision", me->name() + "���˿��������������Ծȥ��\n",
                                environment(me), ({me}) );
                        write("�����˿��������������Ծȥ��\n");
                        me->move(__DIR__"shitou");
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

int do_unlock(string arg)
{
        object room;
        object me = this_player();
        object ob;

        if (arg == "door") {
        if (query("exits/north"))
                return notify_fail("���Ѿ��ǿ����ˡ�\n");

        if (!(ob = present("hys", this_player())))
                return notify_fail("�㲻��������\n");
        message_vision(
        "$N��һ��Կ�״���С�ţ�����Կ��ȴ����.\n", this_player());
        destruct(ob);

       if(!( room = find_object(__DIR__"shulin")) )
                room = load_object(__DIR__"shulin");
       if(objectp(room))
        {
                set("exits/north", __DIR__"shulin");
                message_vision("$Nʹ�����Ŵ��˿�����\n",this_player());
                room->set("exits/south", __FILE__);
                message("vision","�������˰��Ŵ��ˡ�\n",room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }
        return 1;
     }
}

void close_gate()
{
        object room;

        if(!( room = find_object(__DIR__"shulin")) )
                room = load_object(__DIR__"shulin");
        if(objectp(room))
        {
                delete("exits/north");
                message("vision","ֻ��ƹ��һ���������Զ�����������\n",this_object());
                message("vision","���Ժ�������һ����ͷ����⣡����ȥ�ˣ�\n" ,
                         this_object());
                room->delete("exits/south");
                message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);
                message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n" ,
                        room );
        }
}
