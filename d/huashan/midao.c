// Room: /d/huashan/modao.c
// Date: Look 99/03/25

#include <room.h>

inherit ROOM;

void create()
{
	set("short","�ܵ�");
	set("long", @LONG
������ɽ����ڴ���һ���ܵ���ɽ���������һ�ţ�������ֲ��嶫����
����ֻ�ú���Ϲ���ˡ�
LONG
	);
	set("exits", ([
		"left" : __DIR__"rukou",
		"south" : __DIR__"midong",
	]));             
       set("objects", ([
         __DIR__"npc/feng_bp" : 1,
         __DIR__"npc/cheng_by":1,
         __DIR__"npc/cong_bq":1,
       ]));
	set("indoors", "��ɽ" );

        setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    if((objectp(present("feng buping", environment(me))) ||
        objectp(present("cheng buyou", environment(me))) ||
        objectp(present("cong buqi", environment(me)))))
    return notify_fail("���ڵ��Ӵ����ߺ�����͵���ҽ��ڽ��أ����������������뿪��\n");
}                              
