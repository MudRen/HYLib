// Room: /jingzhou/bqku.c
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ǿ��ݱ������ˣ������ܣ�jia)�Ϸ����˸�ʽ�ĵ�ǹ���ȡ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"bqkumen",
	]));

	setup();
	replace_program(ROOM);
}

