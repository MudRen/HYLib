// Room: /d/tangmen/wumiange.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "���߸�");
	set("long", @LONG
	��ת��󣬵��л��������ߡ���������¥����ȡ�����⾳���������й��в�
�ٵ����������ŵ������Ͼۻᣬ���ĵĺõط���
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang15",
		"west" : __DIR__"changlang19",
		"eastup" : __DIR__"jiaolou7",
	]));

	setup();
	replace_program(ROOM);
}

