// by mayue

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
������һ��ͷ�����ǽ����һ��ͨ�̣������ۿ�����������
����Ϣ�����߰���һ���������õ�ľ����һ���η�������������
�ߺȲ衣
LONG
	);
//      set("outdoors", "wudujiao");

	set("exits", ([
		"east" : __DIR__"xiaodian",
//		"south" : __DIR__"milin1",
//		"west" : __DIR__"neijin",
//		"north" : __DIR__"road3",
	]));
        set("objects", ([
                __DIR__"npc/daoshi": 1,
	]));
   

	setup();
	replace_program(ROOM);
}

