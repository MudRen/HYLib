// Room: /u/wsl/changan/boshulin3.c
// This is a room made by wsl.

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һƬ֦��Ҷï�İ����֣����ݳ��ñ�ض��ǣ�������ԭʼ
�����֣����ƺ���ʧ�˷���
LONG
);
	set("exits", ([ /* sizeof() == 8 */
  "southwest" : __DIR__"boshulin3",
  "south" : __DIR__"boshulin3",
  "east" : __DIR__"boshulin3",
  "southeast" : __DIR__"boshulin3",
  "west" : __DIR__"boshulin4",
  "northwest" : __DIR__"boshulin3",
  "north" : __DIR__"boshulin2",
  "northeast" : __DIR__"boshulin3",
]));

	setup();
	replace_program(ROOM);
}
