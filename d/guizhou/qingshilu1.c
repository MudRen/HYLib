inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ������ɫ��ʯ�̳ɵĴ��������������������������
������������ϵĳ��������������ϡ�
LONG );

	set("exits", ([
               "southeast"      : __DIR__"tulu1",
               "north"      : __DIR__"qingshilu2",
		
	]));

 	set("outdoors", "guizhou");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



