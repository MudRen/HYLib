// Room: /u/jpei/thd/njroad1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���ƾɵ�С�Ƶ꣬�����Ѿ��ܾ�û�������˵�
���ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njwest.c",
		"east": __DIR__"njroad2.c",
		"south": __DIR__"xiaodian.c",
	]) );

	setup();
	replace_program(ROOM);
}

