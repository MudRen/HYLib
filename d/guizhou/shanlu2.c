inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��Сɽ·����������ȥ�����Կ���һ������������ľï
ʢ�����Զ��Ǹ߸ߵ���ľ��ż�����м�ֻҰ�ô���������ܹ���
LONG );

	set("exits", ([
                          "southeast"      : __DIR__"shanlu1",
                         "west"      : __DIR__"shanlu3",
		
	]));
	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



