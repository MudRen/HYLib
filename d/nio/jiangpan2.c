// Room: /u/jpei/thd/jiangpan2.c

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
		"northwest": __DIR__"jiangpan1.c",
		"east": __DIR__"jiangpan3.c",
	]) );

	setup();
	replace_program(ROOM);
}

