// Room: /d/tangmen/jingyitang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	�����������ŵ����书����һ������֮�󣬾������޵ĵط���������������
�����ŵ�һ���֣������ųơ�ǧ��ǧ�ۡ��������������뻯����
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"qulang4",
		"east" : __DIR__"dating",
		
	]));
	 set("objects", ([

                __DIR__"npc/tang_liang" : 1,
        ]));


	setup();
	replace_program(ROOM);
}

