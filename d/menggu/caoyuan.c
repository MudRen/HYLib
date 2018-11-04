// Room: /d/menggu/caoyuan.c

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
�纣����ɹŲ�ԭ,����ޱ�,����в�ӥ�ӹ�,������������.���
��ţ�򻺻����ƶ�.�����Ǹ�С����,���泤���˹�ľ��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huazheng.c" : 1,
]));
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"guanmu1",
  "south" : __DIR__"caoyuan2",
  "north" : __DIR__"caoyuan4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
