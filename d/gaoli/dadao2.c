// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
	
������һ����ʯ����ϣ���Ϊս����ԭ��Խ��ǰ������Խ��Խ�٣�
��ʱ����������ҴҶ�������������������޾��ڡ�����ͨ������ǡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"jiangdong",
		"east" : __DIR__"dadao3",
	]));
       setup();
	replace_program(ROOM);
}	
