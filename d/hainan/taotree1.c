// Room: /d/hainan/taotree1.c

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
Ѥ�õ��һ���������,��ȴ��Ҳ�������ȥ��·��.��ǰֻ��һƬ��
��ɫ�Ļ���.����������,�ߵ���������......
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"outtree",
  "east" : __DIR__"taotree1",
  "north" : __DIR__"taotree1",
  "west" : __DIR__"taotree2",
]));

	setup();
	replace_program(ROOM);
}
