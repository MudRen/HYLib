inherit ROOM;

void create()
{
        set("short", "鸦片馆");
        set("long", @LONG
这是鸦片馆内的一个小单间，有几个人正在打麻将。看上
去这个鸦片馆就是他们开的。
LONG);
        set("exits", ([
                 "west" : __DIR__"yanguan",                 
        ]));

        set("coor/x", -230);
	set("coor/y", -30);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}
