// Room: /d/japan/jiedaoe1.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
һ�������Ľֵ�,������һ����������,�����洫���Ķ�����������
�������������ֵ�.������һ�䵱��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jiedaoe2",
  "west" : __DIR__"zhongxin",
  "south" : __DIR__"tiejiangpu",
  "north" : __DIR__"dangpu",
]));

	setup();
	replace_program(ROOM);
}
