// square.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������ѩɽ�ɵ����䳡���������⼸��ľ�ˣ������Ǳ����⣬������
���㳡��ͨ�������ѧѩɽ�ɵ����ڴ�ϰ��������
LONG );
        set("exits", ([ /* sizeof() == 2 */         
            "south"     : __DIR__"bingqifang"
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
