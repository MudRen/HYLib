// Room: /d/sandboy/reed.c

inherit ROOM;

void create()
{
	set("short", "«έ��");
	set("long", @LONG
һƬ��ɫ��«έ��,���������«έ���Ͽ����˰�ɫ��«��,΢�紵��,
��ɫ��«���������.������һƬ�Ӳݴ�.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"inreed",
  "south" : __DIR__"inturf",
]));

	setup();
	replace_program(ROOM);
}
