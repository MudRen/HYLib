inherit ROOM;

void create()
{
    set("short","����");
    set("long", @LONG
��������ݹ��������ң����Ӳ����󣬺�������ӣ����ӵ�������
���룬���ӹ��������������߰���һ���辰��һ��С�������ż����顣
LONG);
	set("exits", ([
	    "south" : __DIR__"lang5",
	    ]));
        set("objects", ([
           __DIR__"npc/furen" : 1,
        ]));
	setup();
        replace_program(ROOM);
}
