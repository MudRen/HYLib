// Room: /u/jpei/thd/njroad4.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·�����ϱ߿��Ѿ����Կ������ˣ���ˮ����������ʱ����
������Ķ��ġ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"njroad3.c",
		"south": __DIR__"njroad5.c",
	]) );
	set("objects", ([
         "/d/xiangyang/npc/boy" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

