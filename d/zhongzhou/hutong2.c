inherit ROOM;

void create()
{
        set("short", "С��ͬ");
        set("long", @LONG
������һ��С��ͬ�����ڰ�������Ҳ�ǻ谵������������
�����˺�ͬ�ľ�ͷ����һ���Ž����š�
LONG);
	set("outdoors", "zhongzhou");
        set("exits", ([
                "north"     : __DIR__"liwu",
                "southwest" : __DIR__"hutong1",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 1,
        ]));

        set("coor/x", -220);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

