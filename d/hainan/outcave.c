// Room: /d/hainan/outcave.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
���ڶ���,��ǰ�ľ�ɫ��������,ͷ���ǰ���Ʈ��,��ǰ�ǻ������.
���һ�Ѹ߸ߵ���ݴ���������������Ķ���.ǰ����Զ��һƬ������
����һ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"dtotree",
  "enter" : __DIR__"cave5",
]));

	setup();
	replace_program(ROOM);
}
