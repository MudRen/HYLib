// shanlu01.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "ɽ·");
		  set("long",@long
�����Ѿ��������ɵĵط��ˣ�·�߻������أ���Ȼ�Ǻ���������ȴ
��Ȼ���������������������޵Ľ�����ǰ��ɽ�Ͼ��������ɵľ����ˣ�
����������ʱ���ɽ�š�
long);
		 set("exits",([
"westdown" : __DIR__"shanmen",
"southup" : __DIR__"shanlu02",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
