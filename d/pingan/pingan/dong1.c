//dong1

inherit ROOM;

void create()
{
  set ("short", "ƽ����·");
  set ("long", @LONG
����ƽ���ǵ�һ����·�����������ƽ���ǡ�·�����һƬ���ӿ�
����Ȼ���Ǻ��£���һ����֪����һ�Ҵ��Ǯׯ�������������������ſڣ�
������һ�Ҳ�С�ĵ���.

LONG);

set("outdoors","pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

set("exits", ([
    "west" : __DIR__"guangchang",
    "north" : __DIR__"bank1",
    "south"  : __DIR__"dangpu",
    "east" : __DIR__"dong2",
]));

//	set("objects" , ([
//		__DIR__"npc/man5" : 1,
//	]));
         setup();
        replace_program(ROOM);
}
