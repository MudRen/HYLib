// Room: /city/libailou.c
// congw 980830

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
����һ������С���ݣ����ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ�
��·ȥ�ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"beidajie2",
"up" : __DIR__"libailou2",			
                	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

