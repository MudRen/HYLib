// Room: /u/jpei/thd/njroad3.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���񷿣�����ܾ�û����ס�����ӡ��ϱ�����
С·ͨ�򽭱ߡ�
LONG
	);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njroad2.c",
		"east": __DIR__"njeast.c",
		"north": __DIR__"yangjia.c",
		"south": __DIR__"njroad4.c",
	]) );

	setup();
	replace_program(ROOM);
}

