// Room: /u/wsl/changan/zao.c
// This is a room made by Wsl.

inherit ROOM;

void create()
{
	set("short", "[31m������[2;37;0m");
	set("long", @LONG
������һ���ľ�����ʯС���У�����������һ�����������Ϸ���
�ĳ�������Ҳ�������Ȼȥ����һ�����㡢һ˿���⡢һ��˿����Զ
����¥�ĸ���������Ʈ����
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ca17",
]));

	setup();
	replace_program(ROOM);
}
