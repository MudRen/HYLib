inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ɫ��ʯ�̳ɵĴ��������������������������
������������ϵĳ��������������ϡ�
LONG );

	set("exits", ([
               "south"      : __DIR__"qingshilu1",
               "northeast"      : __DIR__"xingze",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



