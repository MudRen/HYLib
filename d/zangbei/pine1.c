 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ܸߣ���С����������������Һ�����Ҳ���ܣ�������������Ѿ֦������
�׾��ҵ�Ъ�ŵĵط�����������Ժ�����ؿ���ֱ���µ�Ժ����Ķ�������Ժ���
��ֻ�������ڵ���Ѱʳ���������Ľ����������������
LONG
        );
        set("objects", ([
                
        ]) ); 
        set("exits", ([ 
                "down" : __DIR__"temple5",
        ]));
        set("coor/x",-1080);
        set("coor/y",170);
        set("coor/z",10);
        setup(); 
} 
void init(){ 
        add_action("do_climb","climb");
}  
int do_climb(string arg){ 
        object me,room;
        me=this_player();
        if (!arg || (arg!="pine" && arg!="����")) 
                return 0; 
        room=find_object(__DIR__"pine2");
        if (!objectp(room)) room=load_object(__DIR__"pine2");
        message_vision("$N�ֽŲ��ã����ݵؼ�����������ȥ��\n",me);
        tell_room(room, this_player()->name() + "����������������\n");
        this_player()->move(room);
}    
