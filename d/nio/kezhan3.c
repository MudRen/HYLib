// Room: /u/jpei/thd/kezhan3.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
һ����ͨ�Ŀͷ���ֻ��һ�Ŵ���һ�Ų��Ƶ����ӡ�
LONG
	);
	set("sleep_room", 1);
	set("hotel", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);

	set("exits", ([
		"west": __DIR__"kezhan2.c",
	]) );

	setup();
	replace_program(ROOM);
}
