// square.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
��������ң�ɵ����䳡���������⼸��ľ�ˣ��ϱ��Ǵ����ݣ�
ͨ���������ң�ɵ����ڴ�ϰ��������
LONG );
        set("exits", ([ /* sizeof() == 2 */         
            "south"     : __DIR__"bingqif"
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}


