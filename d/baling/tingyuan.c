
inherit ROOM;

void create()
{
	set("short", "ͥԺ");
	set("long", @LONG
������һ�����Ĵ�Ժ��Ժ�ڸɸɾ�������Ȼ̸�����ݻ�������һ
��Ҳ�ܿ�������һ�����˼ҡ�
LONG);

	set("exits", ([
                "west" : __DIR__"xiangfang1",
                "east" : __DIR__"xiangfang2",
                "south" : __DIR__"xiangfang3",
                "southeast" : __DIR__"houyuan",
                "north" : __DIR__"haozai",
	]));

 	set("outdoors", "baling");
      /*  set("objects", ([
		__DIR__"npc/jiading":2,
	]));*/
	setup();
	replace_program(ROOM);
}


