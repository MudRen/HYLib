// /d/xingxiu/silk2.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵����������������ɽ���������������
������һ���������������ԭ��������ͨ������
LONG );
        set("outdoors", "xingxiuhai");
   set("objects" , ([
     "d/gaochang/npc/liwenxiu" : 1,
   ]));

        set("exits", ([
            "east" : __DIR__"silk1",
            "west" : "/d/mingjiao/westroad1",
            "northwest" : __DIR__"silk3",
            "north" : "d/gaochang/road",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

