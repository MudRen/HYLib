// Room: /d/tangmen/paifang.c
// BY hem
inherit ROOM;

void create()
{
	set("outdoors", "tangmen");
	set("short", "ź����Ʒ�");
	set("long", @LONG
	����һ���ߴ���Ʒ���ȫ���ɴ���ʯ���ɣ����������Ծ������Ĵ��֡�ź��
�������������Ʊ߶��͵񻨡����Ͼ����Ƽұ��ڵ�ź������������Ʈ���������㡣									 
LONG
	);
	

	set("exits", ([
		
		
		"north" : __DIR__"huayuan5",
		"south" : __DIR__"qulang1",
		
	]));

	setup();
	replace_program(ROOM);
}

