// Room: /d/sandboy/road2.c

inherit ROOM;

void create()
{
	set("short", "�﹡");
	set("long", @LONG
�﹡���߳���������ɫ�����,��໹�����������Ļ���.һ����ȥ,��
ǰ�ǽ�Ӳӵ�һƬ����,�쵽���ո��ʱ����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1",
  "south" : __DIR__"daotian3",
  "north" : __DIR__"ground",
]));

	setup();
	replace_program(ROOM);
}
