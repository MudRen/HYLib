// Room: /d/japan/jiedao.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�����û��ົ����һ���ֵ�,ʮ�ֵĿ�.��Ȼ��������,�������ڵ�
������ʱ���������,������Ҫ�ǲ�С��ˤ����,�������Щʲô.�ֵ��Ķ�
����һ���õ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yijiguan",
  "south" : __DIR__"nanmen",
  "north" : __DIR__"jiedaos",
  "east" : __DIR__"lvdian",
]));

	setup();
	replace_program(ROOM);
}
