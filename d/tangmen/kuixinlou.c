// Room: /d/tangmen/kuixinlou.c
// BY hem
inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
	������ź������϶ˣ������Ÿߴ�Ŀ���¥��������������ר�Ź������˵�
�������ķ�������ʢ������¥�����п�����¥�����㣬����ϵõ����㣬�����
����ź��������������ÿ���¥��ӭ����������飬���ֱʣ��������͵Ŀ��ǡ�����
�Ǻ�ľ���ݣ����Ե��ڶ��㡣
LONG
	);
	

	set("exits", ([
		
		"northwest" : __DIR__"qulang6",
		"south" : __DIR__"huayuan10",
		"up" : __DIR__"kuixinlou2",
	]));

	setup();
	replace_program(ROOM);
}

