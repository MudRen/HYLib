// Room: /d/jingzhou/road1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����ʯ����ϡ�����ͨ�����ݳǡ�
LONG
        );
        set("exits", ([
  "northeast" : "/d/city/ximen",
  "west" : __DIR__"road2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

