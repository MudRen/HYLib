// Room: /u/jpei/thd/jiangpan3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ���󽭺�ب����ǰ����ˮ�ƺƣ�����ҹҹ�������ݵر���󺣡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"jiangpan2.c",
	]) );

	setup();
	replace_program(ROOM);
}

