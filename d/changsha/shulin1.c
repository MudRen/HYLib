// Room: /d/shaolin/shulin1.c
// by pishou

inherit ROOM;




void create()
{
    set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء�������ϵ�һ��������ס��һ
·����������, �Եø���ƽ����
LONG
	);

	set("exits", ([
        "southwest" : __DIR__"eroad3",
        "east" : "/d/yanping/gudao2",
	]));

 	set("outdoors", "leshou");
	setup();
	replace_program(ROOM);
}



