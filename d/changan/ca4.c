// Room: /u/wsl/changan/ca4.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����ס��һ����������Ͽ�����δ�ܸ��У�һֱס���⣬׼����
�´��ٽ����ƿ���
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ca3",
]));

	setup();
	replace_program(ROOM);
}
