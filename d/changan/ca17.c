// Room: /d/changan/ca17.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "�����Ǵ��");
	set("long", @LONG
�����ľ������������������治��Ϊ���Թų�����������������
�ǳ����������Ĳ�ׯ��������һƬ�����де������֡�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ca1",
  "west" : __DIR__"ca",
  "south" : __DIR__"zao",
  "east" : __DIR__"dongmen",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiao-fan" : 1,
]));
	set("outdoors", "changan");

	setup();
	replace_program(ROOM);
}
