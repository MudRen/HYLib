// shanlu1.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����ɽ·");
		  set("long",@long
���н���������һ������һ�죬����������������ǿ����;������ʲôǿ
����ֻ�ǻ�ɳ���棬����͸�ǣ�ȴҲ��ʵ�Ѱ���
long);
		 set("exits",([
"westup" : __DIR__"shanlu2",
"east" : __DIR__"shanlu",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
