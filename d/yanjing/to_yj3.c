// Room: /d/yanjing/to_yj3.c

inherit ROOM;

void create()
{
	set("short", "ʢ�����");
	set("long", @LONG
�׷������ѩ�µ�Խ������,ͷ���ܿ�ʹ�����ѩñ.������ǰ����
�����Ľ���ӡ,�ܿ�ͱ�ѩ����û��.���߲�Զ����[ʢ��]��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"to_yj2",
  "north" : __DIR__"gate",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
