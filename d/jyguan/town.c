// town.c С��
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "С ��");
	set("long",   @LONG
����һ���ɱ������߽�ʿ�Ҿ�۾Ӷ��γɵ�С������ɳĮ֮������
��������Ʒ���ڴ˽��ף�������������Ŀ�е�һ����䡣��������������
Ҳû��ʲô�����ˡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
//	          "west" : __DIR__"luzhou1",
//              	"east" : __DIR__"shamo",
                "south" : __DIR__"townroad",
//                "north" : __DIR__"shamo",
                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
                __DIR__"npc/shangren" : 1,
		"/d/shaolin/npc/tiao-fu" : 2,
                __DIR__"npc/xiao-fan" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}

