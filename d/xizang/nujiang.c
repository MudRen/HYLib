 inherit ROOM;
void create()
{
      set("short", "ŭ��"); 
        set("long", @LONG
��ӿ����³�ز����������ˣ�����ͻȻ��խ����ˮŭ���İ���������ף��·�
һ���ݷ�ǧ��Ĳ������ڰ��β�ס������֮־�������ţ�ŭ���ţ������š�����һ
ȺҰ���������ڵ�����ɱ��š�
LONG); 
         set("exits", ([ 
        "northwest" : __DIR__"tearoad2",
        "south" : __DIR__"yuema",	
        ]));
        set("outdoors", "guanwai"); 
        set("type","street");
        set("objects", ([
                __DIR__"npc/yema" : 1,
        ]) ); 
        set("coor/x",-990);
    set("coor/y",-200);
        set("coor/z",0);   
        setup();
        replace_program(ROOM);
}    
