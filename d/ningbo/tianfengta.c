// Room: /u/beyond/ningbo/tianfengta.c �����
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������������Ǹ�����ߵĽ������ˣ����ǵ������������ˡ���ʿ����
����Ҫ����������һ��ȫ�Ƿ�⣬�����������²�����ӽ��
LONG
	);
        set("objects",([
        __DIR__"npc/you" : 1,
        ]));
	set("exits", ([
	"north" : __DIR__"shilu",
        "east" : __DIR__"aywsi",
        "south" : __DIR__"ttcsi",
	]));
	setup();
        replace_program(ROOM);
}
