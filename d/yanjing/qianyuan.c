// Room: /d/yanjing/qianyuan.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
һ�Ű���ʯʯ�״Ӵ���ֱͨ���������,�����Ƿ��軨ľ,������
����Ʈ���ڿ�����,����÷���ĺ�֦���µ��쵽ʯ����,��ľ��Ļ�ѩ
��δ�ܻ�,���ķ�������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"qianting",
  "south" : __DIR__"wangfu",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
