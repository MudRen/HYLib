
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���ݶ���");
	set("long", @LONG
���Ƕ����ţ��������Ϸ��̵��и������������֡���ǽ�����ż�
�Źٸ���ʾ��һ����·����ͨ��ӱ���
LONG );
	set("exits", ([
		"west" : __DIR__"dongdajie",
		"east" : __DIR__"dadao5",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

