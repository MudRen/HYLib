// Room: /d/menggu/road1.c

inherit ROOM;

void create()
{
	set("short", "Ӫ�ʼ�");
	set("long", @LONG
��Ŀ����,�Ƕ������������Ӫ��,һ������һ��,�ɹŲ�������Ϊ��,
ƽʱ��ס�����ɹŰ�,��ⷽ��.�����е�ͨ�򼸸���Ļ,�ֱ��������ʹ�
�ǵ�ס��,������ԯ��,�������ӭ����չ.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwei1.c" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road",
  "east" : __DIR__"road2",
  "west" : __DIR__"road3",
  "south" : __DIR__"yuanmen",
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
