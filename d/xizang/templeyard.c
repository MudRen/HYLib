 inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
׳������Ժ������ȴʮ����ɭ�İ�����ǧֻ�������ţ����ȼ�ϵ���ͭ���ڷ�
�����������صĻ��档���ʵ���ǽ�ϻ������������裬��������Ŀ�����ľ�����ɫ
��������������У����Եù��ؿɲ���
LONG
        );
      
        set("exits", ([ 
                "east" : __DIR__"dazhaotemple",
                "west" : __DIR__"tower",
                "north" : __DIR__"wallhole",
        ]));
        set("objects", ([
                "/clone/npc/man" : 3,
        ]));
        set("outdoors", "guanwai");
        set("coor/x",-1220);
        set("coor/y",-10);
        set("coor/z",0);
        set("coor/x",-1220);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
