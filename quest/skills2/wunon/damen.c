// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "ũׯ����");
	set("long", @LONG
������ũׯ����,����������������ũׯ��,��ר������
����ʳ��ĵط�,�������ѧϰ�����,��ô����ҶԵط���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "north" : "d/beijing/road2",
                "south" : __DIR__"daotian1",
        ]));

	set("objects", ([
		"d/city/npc/xunbucao" : 2,
	])); 

	setup();
	replace_program(ROOM);
}
