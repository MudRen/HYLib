// This is a room made by wsl.
inherit ROOM;
int do_zuan(string arg);
void create()
{
    set("short", "ʯ��");
    set("long", @LONG
��·������һ�����������ɰ����ڣ��Ķ�ʯ���ٱ������֣���
�������ŵ��¶�Ѩ��Ҳ����˺ƴ�����֣�Ҫ���ǹ��߰��˵㣬����
�������͵�����ʲô����
LONG
);
    set("exits", ([
       "south" :__DIR__"shidao",
]));
    setup();
}
void init()
{
        add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
        object ob,room;
        ob = this_player();
        room=load_object("/d/changan/qinhuang/songlin.c");
        if( !arg || arg=="" ) return 0;
        if( arg=="����" ) {
                message_vision("$N׳��׳����һͷ����������\n", ob);
        ob->move(room);
        write("���ͷ���˿����Ѿ�û����·�ˡ�\n");
//        tell_object(ob, "�������������˺ܾúܾ�.......\n" NOR ) ;
        call_out("songlin", 20 , ob );
        return 1;
        }
}
void songlin(object ob)
{
        if(!ob) return;
        tell_object(ob, "�����˸������������߳�����Ƭ���֡�\n");
        ob->move("/d/changan/qinhuang/dadian.c");
        ob->set("food",1);
        ob->set("water",1);
}
