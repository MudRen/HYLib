// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ����������߾��Ǹ����ı��Ǽ����ˡ������Ѻ
�Ÿ�������Ҫ���ˣ�ƽʱ�кܶ�ٱ���������ء�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"shanlu12",
               	"west":__DIR__"shanlu15",
	]));
       setup();
	
}

