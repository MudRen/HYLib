// Room in ����
inherit ROOM;
void create()	
{
	set("short", "ɳ̲");
	set("long", @LONG	
������ɳ̲֮�ϣ�����������ĺ�ɳ���ϱ���һ���޼ʵĴ󺣡�Զ
Զ��ȥ�����м��Ҵ�ͣ���ڰ��ߣ��ں��˵ĳ���²�ס��ҡ�Ρ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northwest" : __DIR__"dadao9",
		"southeast":__DIR__"shatan2",
	]));
	set("objects", ([
	"quest/skills2/wunon/yu/yutan" : 2	,   
	
	]));	
       setup();
	replace_program(ROOM);
}	
