// Room: /d/hainan/dong.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"underhill3",
]));
        set("objects", ([
                __DIR__"npc/xiaoyi" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
