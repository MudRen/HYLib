// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ����������߾��Ǹ����ı��Ǽ����ˡ����߾���
���Ǽ����Ĵ����ˡ��м����ٱ�����������ţ����������������㡣
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"shanlu15",
               	"west":__DIR__"jianju",
	]));
       setup();
	
}

