// /d/gaoli/dafujia2
// Room in ����
// rich 99/03/28
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIC"��֮��"NOR);
        set("long", @LONG
���Ų��߽���ҵĴ����������������õļ�������ݳޣ�һ����֪
��������ͨ������ס�ĵط������а���һ��ɼľԲ���ͼ������ӣ�����
��һ�׾��µ����˴�����
LONG
);
        set("exits", ([ 
        "south" : __DIR__"dafujia1",
	]));
set("objects", ([
		"/d/gaoli/npc/jin" : 1,
		__DIR__"npc/yahuan":1,
	]));
      setup();
	replace_program(ROOM);

}
