// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������طǳ���æ����ʱ������������
�ҴҶ���������ͨ������ǡ������Ǻ����ˣ�������������������˵�
������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadao6",
		"west":__DIR__"xiaolu1",
		"southwest":__DIR__"suishilu1",
		"southeast":__DIR__"shatan1",
	]));
       setup();
	replace_program(ROOM);
}	
