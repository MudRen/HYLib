// liangongfang.c (kunlun) ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ��������ż����㣬����������
�𡣼�λ�����ɵ�������ϥ�������������
LONG
	);
	set("exits", ([
		"south" : __DIR__"sanshengtang",
		"north" : __DIR__"xiuxishi",
		"east"  : __DIR__"chufang",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));

	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
