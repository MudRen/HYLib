// Room: /u/wsl/changan/boshulin8.c
// This is a room made by Wsl.

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
  "southwest" : __DIR__"boshulin8",
  "south" : __DIR__"boshulin8",
  "east" : __DIR__"boshulin8",
  "southeast" : __DIR__"boshulin7",
  "west" : __DIR__"boshulin8",
  "northwest" : __DIR__"boshulin8",
  "north" : __DIR__"boshulin8",
  "northeast" : __DIR__"boshulin9",
]));

	setup();
	replace_program(ROOM);
}
