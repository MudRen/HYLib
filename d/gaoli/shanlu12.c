// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ������ϱ��߲�Զ���Ǹ������������ˡ�����û
��ʲô�ˣ���������ġ������Ѿ��Ǹ����ı����ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"shanlu11",
        	"north":__DIR__"shanlu13",
        	"west":__DIR__"shanlu14",
	]));
       setup();
	
}

