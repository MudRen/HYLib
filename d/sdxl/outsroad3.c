// /d/xiangyang/outsroad3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ڶ��潻�����·�ϣ�ż��������������ҴҶ��������Ͼ��Ǻ��Ͼ�
���ˣ�����ͨ�������ǡ�
LONG
	);
        set("outdoors", "xiangyang");

	set("exits", ([
		"north" : __DIR__"outsroad2",
                "westup" : __DIR__"conglin1", 
	]));

	setup();
	replace_program(ROOM);
}

