// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
	
������һ����ʯ����ϣ���Ϊս����ԭ��Խ��ǰ������Խ��Խ�٣�
��ʱ����������ҴҶ�������������������޾��ڡ��ϱ�ͨ��ټ�,
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"sanchalu",
		"south" : __DIR__"yuanmen",
	]));
       setup();
	replace_program(ROOM);
}	
