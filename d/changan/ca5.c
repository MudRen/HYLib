// Room: /u/wsl/changan/ca5.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ������ª�Ŀͷ�,�����м��Ŵ����м����һ��̨��̨
�Ϸ���һ������ͼ������ӡ�
LONG
);
	set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ca3",
]));
	set("no_magic", "1");

	setup();
	replace_program(ROOM);
}
