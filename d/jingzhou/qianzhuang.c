// Room: qianzhuang.c
// congw 980830
inherit ROOM;

void create()
{
	set("short", "����Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ�����е���Ʊ
�����ǳ��ã�ͨ��ȫ����
LONG
	);

	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
set("no_fight",1);
	set("objects", ([
		__DIR__"npc/qian" : 1
	]));

	setup();
	replace_program(ROOM);
}

