// wdroad8.c ����·
// netkill

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY "����·" NOR);
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������һ����ɽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad7",
		"west" : __DIR__"shanmen",
	]));
//	set("objects", ([
//		__DIR__"npc/yetu" : 4 ]));

	setup();
	replace_program(ROOM);
}

