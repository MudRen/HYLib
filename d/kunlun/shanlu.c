// shanlu.c (kunlun)

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
"west" : __DIR__"shanlu1",
"east" : __DIR__"zhenyuanqiao",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
