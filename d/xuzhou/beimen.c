
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���ݱ���");
	set("long", @LONG
���Ǳ����ţ��������Ϸ��̵��и������������֡���ǽ�����ż�
�Źٸ���ʾ��һ����·����ͨ��ɽ����
LONG );
	set("exits", ([
		"north" : __DIR__"dadao10",
		"south" : __DIR__"beidajie",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

