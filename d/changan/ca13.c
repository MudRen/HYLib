// Room: /d/changan/ca13.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����Ǵ��");
	set("long", @LONG
����Ϊ�С��ش������֮�Ƶĳ����ǣ������������ַǷ�����
��������һ�����֣�������Ǵ�С�����������ˡ�
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"ca16",
  "north" : __DIR__"ca12",
  "south" : __DIR__"ca34",
]));
	set("outdoors", "changan");

	setup();
	replace_program(ROOM);
}
