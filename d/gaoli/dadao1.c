// /d/gaoli/baihuuedajie3
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
		"west" : __DIR__"baihumen",
                "southwest" : __DIR__"dadao8",
		"east" : __DIR__"jiangkou",
	]));
       setup();
	replace_program(ROOM);
}	
