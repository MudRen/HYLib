// Room: /d/jindezheng/shulin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG
	);
	set("no_sleep", 1);
	set("no_dazuo", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street3",
  "southwest" : __DIR__"shulin2",
]));
	set("outdoors", "jindezheng");

	setup();
	replace_program(ROOM);
}
