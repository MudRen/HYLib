//mudong.c
// This is a room made by Wsl.
inherit ROOM;
int do_use(string arg);
void create()
{
        set("short", "ĹѨ");
        set("long", @LONG
����Լ�������ܵ�ǽ�ϲ���������ѡ�
LONG
);
        setup();
}
void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 15, this_object());
             write(
"��ȡ������һ�Σ�����ǰȥ��ȼ�����е�һֻ��ѣ�Ҳ��֪��ʲô���أ�
��������ֻ���һһȼ��������\n");
        set("long", @LONG
����һƬ���ң����ֿ��ױ���ɢ���ڵ��ϣ������Ͽ��˸��ָ���
��ͼ����������ͨ�˴Ҳ��֪������ʲô���ذ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"mudong"+random(10),
                "south" : __DIR__"mudong"+random(10),
                "east" : __DIR__"mudong"+random(10),
                "west" : __DIR__"mudong"+random(10),
        ]));
           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("�����ȼʲô��\n");
        }
}

void close(object room)
{
        message("vision","��һ�����ǽ�ϵĻ�Ѿ�Ϩ���ˡ�\n", room);
        set("long", @LONG
����Լ�������ܵ�ǽ�ϲ���������ѡ�
LONG
);
        room->delete("exits");
}

