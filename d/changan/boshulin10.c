// Room: /u/wsl/changan/boshulin10.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��Ȼ���ʣ������߳�����Ƭ�����֣�����������һƬ�Ӳ�
�����Ĳݵء�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"boshulin9",
  "east" : __DIR__"caodi",
]));

	setup();
	replace_program(ROOM);
}
