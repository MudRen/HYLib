//Cracked by Kafei
// Room: /d/xixia/huilang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������԰��Ļ��ȣ������������������ȶ��Ƿ��������ߣ�
�������Ű���ʯ�塣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huilang",
  "north" : __DIR__"garden",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
