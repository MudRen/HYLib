// Room: /d/sandboy/road1.c

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
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"pond",
  "east" : __DIR__"road2",
  "south" : __DIR__"daotian1",
  "north" : __DIR__"daotian2",
]));

	setup();
	replace_program(ROOM);
}
