// Room: /u/wsl/changan/boshulin7.c
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
  "southwest" : __DIR__"boshulin7",
  "south" : __DIR__"boshulin7",
  "east" : __DIR__"boshulin7",
  "southeast" : __DIR__"boshulin7",
  "west" : __DIR__"boshulin6",
  "northwest" : __DIR__"boshulin8",
  "north" : __DIR__"boshulin7",
  "northeast" : __DIR__"boshulin7",
]));

	setup();
	replace_program(ROOM);
}
