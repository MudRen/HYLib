// /d/gaoli/maji
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��");
	set("long", @LONG
��������Ȼ����ͻ������ô�ߴ󣬵�ȴ���߳�;�����������ʽ
��������Ӧ�о��У�ͻ�����������������������С�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
               "south":__DIR__"qinglong-1", 
	]));
set("objects", ([
		"/d/gaoli/npc/ma" : 1,
	]));
       setup();
	replace_program(ROOM);
}	
