// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
������һ����̡��Ա߾�����ӿ�Ĵ󺣣������紵���������Ĵ�
�ŵ̰������������϶��Ǻ�ˮ�����ϱ���ȥ��һ���ۿ��Ѿ�ӳ�������ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadi3",
        	"southeast":__DIR__"dadi5",
	]));
       setup();
	
}
