// Room: /u/jpei/thd/njwest.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��С���������ڡ����Ӻ�С��������һƬ�ž��С��ϱ���Լ����
����һ���󽭡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"northwest": __DIR__"road2.c",
		"east": __DIR__"njroad1.c",
	]) );

	setup();
	replace_program(ROOM);
}

