inherit ROOM;

void create()
{
        set("short", "С��ͬ");
        set("long", @LONG
������һ��С��ͬ�����ڰ�������Ҳ�ǻ谵������ 
LONG);
	set("outdoors", "zhongzhou");
        set("exits", ([
                 
                "southwest" : __DIR__"hutong",
                "northeast" : __DIR__"hutong2",                  
        ]));

        set("coor/x", -230);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
