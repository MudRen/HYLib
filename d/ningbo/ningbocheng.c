// Room: /u/beyond/ningbo/ningbocheng.c ������
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�������Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ���ر�����
���������������ˣ����������𸽽�ɽ�ϵĲݿܡ�����һ�Ӷӹٱ�����ȥȥ��
һ��ɭ����������ĺ��������⽻������Ҫͨ����
LONG
	);
        set("objects",([
        __DIR__"npc/wujiang" : 1,
        __DIR__"npc/bing" : 3,
        ]));
	set("exits", ([
	"west" : __DIR__"ttcsi",
        "northwest" : __DIR__"aywsi",
        "south" : __DIR__"kedian",
        "east" : __DIR__"dongqianhu",
	]));
	setup();
        replace_program(ROOM);
}
