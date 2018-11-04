// Room: /d/sandboy/inturf.c

inherit ROOM;

void create()
{
	set("short", "�ݴ���");
	set("long", @LONG
��ǰ��һƬ������é��,����ǵ���ɫ��,���м���������ɫ��Ӳ��ï��.
�����ε�ҶƬ��Ե����СС�ľ��,�����ǳ�ʪ������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"turf",
  "north" : __DIR__"reed",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwa.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
