// shanlu01.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "ɽ·");
		  set("long",@long
����һ����ɽ��·��·�߻������أ�·���ƺ��ܾ�û�������ˣ��Ե�
��Щ�ƾɣ����Ǵ������ĺۼ���ϡ���Կ�������ĻԻ͡�������ɽ�£�
����ɽ���������ɵ����ڡ�
long);
		 set("exits",([
"northdown" : __DIR__"shanlu01",
"southup" : __DIR__"shanlu03",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
