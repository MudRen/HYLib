// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
������һ����̡��Ա߾�����ӿ�Ĵ󺣣������紵���������Ĵ�
�ŵ̰������������϶��Ǻ�ˮ�����߾��Ǹ����ķɷ����ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northeast" : __DIR__"qinglongmen",
        	"southwest":__DIR__"dadi2",
	]));
       setup();
	
}
