// Room: /d/menggu/road.c

inherit ROOM;

void create()
{
	set("short", "Ӫ�ʼ�");
	set("long", @LONG
��Ŀ����,�Ƕ������������Ӫ��,һ������һ��,�ɹŲ�������Ϊ��,
ƽʱ��ס�����ɹŰ�,��ⷽ��.�����һ��Ӫ��ǰһ�˸߸ߵĳ�����Ʈ
�ż��ư�ë,�������ڴ����Ǵ󺹾Ӵ�.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwei1.c" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yinzhang",
  "south" : __DIR__"road1",
]));

	setup();
	replace_program(ROOM);
}
