// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ���");
	set("long", @LONG
	
������һ����ʯ����ϣ���Ϊս����ԭ��Խ��ǰ������Խ��Խ�٣�
��ʱ����������ҴҶ�������������������޾��ڡ�����ͨ�������,
������һ����·ͨ��һ��ׯ԰��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"dadao2",
		"east" : __DIR__"dadao4",
//              "northwest" : __DIR__"tulu1",
	]));
       setup();
	replace_program(ROOM);
}	
