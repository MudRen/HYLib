//Cracked by Kafei
// Room: /d/xixia/yushanfang.c

inherit ROOM;

void create()
{
	set("short", "���ŷ�");
	set("long", @LONG
�������ŷ������᷿����λ����������ס�������᷿���ŷ�
������ס�ġ������ǲ񷿡�Ժ�Ӵ�ɨ�ĺܸɾ����м���һ��ˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"bingku",
  "north" : __DIR__"chaifang",
  "west" : __DIR__"huilang",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
