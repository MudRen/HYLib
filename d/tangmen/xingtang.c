// Room: /d/tangmen/xingtang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	���������ŵ����á�����̫̫�Ź�ɭ�ϣ������ô����ŵ��˺ͷ�������µ�
�Ӵ����Ͳ����ġ����������������ǽ�����������ɷ�ǣ�������ĥ�˸����ж�������
�ã�������������ϣ��ض�������������
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"dating",
		"east" : __DIR__"bingqiku",
	]));
	 set("objects", ([

                "/d/tangmen/npc/tang_wuqing" : 1,
        ]));



	setup();
	replace_program(ROOM);
}

