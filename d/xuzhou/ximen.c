
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
���������ţ��������Ϸ��̵��и������������֡���ǽ�����ż�
�Źٸ���ʾ��һ����·����ͨ��ӱ���
LONG );
	set("exits", ([
		"east" : __DIR__"xidajie",
		"west" : __DIR__"dadao",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

