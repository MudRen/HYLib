// Room: /u/wsl/changan/boshulin6.c
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
  "southwest" : __DIR__"boshulin6",
  "south" : __DIR__"boshulin6",
  "east" : __DIR__"boshulin7",
  "southeast" : __DIR__"boshulin6",
  "west" : __DIR__"boshulin5",
  "northwest" : __DIR__"boshulin6",
  "north" : __DIR__"boshulin6",
  "northeast" : __DIR__"boshulin6",
]));

	setup();
	replace_program(ROOM);
}
