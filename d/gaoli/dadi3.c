// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
������һ����̡��Ա߾�����ӿ�Ĵ󺣣������紵���������Ĵ�
�ŵ̰������������϶��Ǻ�ˮ��������ȥ����һ���޼ʣ������Ǳ߾�
��ս�ҵ���ԭ�ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadi2",
        	"south":__DIR__"dadi4",
	]));
       setup();
	
}
