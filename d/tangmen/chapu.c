#include <room.h>
// Room: /dream/chapu.c
// HEM 1998/9/28 
#include <room.h>

inherit ROOM;

void create()
{
//	set("outdoors", "tangmen");
	set("short", "����");
	set("long", @LONG
	����·��һ����ª�Ĳ��̣���Χ�������ֻ��ƣ������������ģ��򵥵ļ�����
��.���Σ�ʱ��ʱ��������ЪЪ�ţ����������򻨲衣���̵������Ǹ�ʮ��.�����С��
��ɰ�����������������ǲ��Ȳ裬������Ҳ�Ǻܿ��ĵ��¶����ϱ���һ�����������š�

LONG
	);
        set("exits", ([	
       	"south" : __DIR__"zhulin",
        "west"  : "/d/jingzhou/shudao10",
	]));
create_door("south", "����", "north", DOOR_CLOSED);

	set("objects", ([
		__DIR__"npc/tangtian" : 1,
	]));

	setup();
	replace_program(ROOM);
}

