// Room in ����
inherit ROOM;
void create()	
{
	set("short", "С·");
	set("long", @LONG
������һ��С·֮�ϡ�������һ����ʯ��·���ϱ߾��Ǻ����ˣ���
�����������������ӿ����������ʱ�м�ֻ��Ÿ�����ͷ�Ϸɹ���
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"dadao9",
		"southwest":__DIR__"xiaolu2",
	]));
       setup();
	replace_program(ROOM);
}	
