// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ��ϱ߾��Ǹ������������ˡ���������˲��Ǻ�
�ࡣ����ƽʱ�������˵���������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southeast" : __DIR__"shanlu9",
        	"northwest":__DIR__"shanlu11",
	]));
       setup();
	
}

