// Room: /dream/zhulin.c
// HEM 1998/9/18
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	����һƬ�����де����֣�����ˮ�����ʺ��������������Ƭ��������������
���࣬ϸϸ��������״���޺��ǵ��޺��������������������б�ֱ��׳�����..
��Ҷ�����㣬���������У��Ŀ����������ֶ��ϣ���һ����ʯ���ɵ�С·��
LONG
	);
        set("outdoors", "tangmen");
	set("exits", ([
		"north" : __DIR__ "chapu",
                "southeast" : __DIR__ "feicui",
	]));
        set("objects", ([
                "/clone/misc/dache": 1,
	]));	
create_door("north", "����", "south", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

