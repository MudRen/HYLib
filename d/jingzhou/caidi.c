// Room: caidi
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "�˵�");
	set("long", @LONG
�㿴��һƬ�����͵Ĳ˵أ������˸��ָ����Ĳˣ����Ĳˡ���ͷ�ˡ��ײˡ�������

LONG
	);

	set("exits", ([
		"east" : __DIR__"whouyuan",
		]));

	setup();
	replace_program(ROOM);
}

