// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ����������߾��Ǹ����ı��Ǽ����ˡ��������
��û��ʲô���ˣ������Ǹ߸ߵ�Χǽ����������Щ��ɭ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"shanlu14",
               	"northwest":__DIR__"shanlu16",
	]));
       setup();
	
}

