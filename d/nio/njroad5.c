// Room: /u/jpei/thd/njroad5.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·���ϱ߾���Ǯ�����ˣ��Ǳߵ����¾ۼ���һЩ����
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad4.c",
		"south": __DIR__"jiangpan1.c",
	]) );

	setup();
	replace_program(ROOM);
}

