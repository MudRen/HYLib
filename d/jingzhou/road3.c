// Room: /d/jingzhou/road3.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����ʯ�������ͨ�����ݡ�������ȥ��ֻ��һ����ɽ
���ɹŰأ�һƬ��÷羰��
LONG
        );
        set("exits", ([
  "east" : __DIR__"road2",
  "northwest" : __DIR__"road4",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);
}

