// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������طǳ���æ����ʱ������������
�ҴҶ���������ͨ������ǡ���������һ��ͨ��Ͼ����Ĵ����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"zhuquemen",
		"south" : __DIR__"dadao9",
                "northeast" : __DIR__"dadao7",
	]));
       setup();
	replace_program(ROOM);
}	
