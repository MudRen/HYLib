// Room: /d/hainan/dtotree.c

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
һ��СС��ɽ·,�Ѿ��챻·�ߵ�Ұ����ס��,�����ܾ�������û����
����,����ֻҪ������Ҷ,�㻹���ܷ�������С·��Ȼ���ô��׵���ĸ�̳�
��,���������������������ǲ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"outcave",
  "northeast" : __DIR__"outtree",
]));

	setup();
	replace_program(ROOM);
}
