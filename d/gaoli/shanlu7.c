// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ��ϱ߾��Ǹ������������ˡ�����ĵ��������
��Щ��᫡���������˱Ƚ϶ࡣ�м��������ڸ�����Ұ�ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"shanlu6",
        	"north":__DIR__"shanlu8",
	]));
       setup();
	
}

