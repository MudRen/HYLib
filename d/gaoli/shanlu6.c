// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ��ϱ߾��Ǹ������������ˡ��кܶ����˴����
�����߹���˵�����������ĸ�������������ķ���Ҫ��ʤ������ս��
����ԭ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southwest" : __DIR__"xuanwumen",
        	"northeast":__DIR__"shanlu7",
	]));
       setup();
	
}

