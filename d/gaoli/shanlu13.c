// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ����������᫣�ż���м�ֻҰ�ô����������
�������߾��Ǹ����ı����̨�ˡ��м����ٱ��������������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"shanlu12",
        	"northup":__DIR__"beifenghuotai",
	]));
       setup();
	
}

