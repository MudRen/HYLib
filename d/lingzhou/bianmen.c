//Cracked by Kafei
// Room: /d/xixia/bianmen.c

inherit ROOM;
#include "room.h"
void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻʹ��ı��ţ��������������ǳ���֮�ã���������Ķ���
һ�㶼�ɴ����룬��Ϊ�Ƚ�ƫƧ����������ʿҲ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chaifang",
  "east" : __DIR__"biangate",
]));
	set("objects", ([
		__DIR__"npc/hgshi" : 2,
	]));
	create_door("west","ľ��","east",DOOR_CLOSED);	
	set("outdoors", "xixia");
	set("cost", 1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="west") {
	if (present("wei shi", environment(me)))
                return notify_fail("��ʿ������һ�����������ǲ������ܽ�ȥ�ĵط���\n");
	}	
        return ::valid_leave(me, dir);
}
