// by mayue

inherit ROOM;

void create()
{
	set("short", "ʯ϶");
	set("long", @LONG
������һ����ʯ�ķ�϶��խ��Ҫ�˲����������������۵��ҷ�
��ǰ��ȥ�����ܺ�����ģ�ֻ�н��µ�ɰʯ������΢�����졣
LONG
	);
//       set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"shixi",
              "down" : __DIR__"baidu2",
 		"westdown" : __DIR__"mishi",
//		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

