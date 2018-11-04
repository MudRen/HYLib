// Room: /d/yandang/luoyan24.c

inherit ROOM;

void create()
{
	set("short", "������ ");
	set("long", @LONG
����һƬ�����֣���˵�ǵ����������˴��Ϻ���������,�����Ѿ�
����С�۴�ϸ,��˼��⾫��,��Ҷ�����罣,���������������������
��,���˻س�����,���ɻ���ͯ��ʱ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luoyan31",
  "east" : __DIR__"luoyan23",
  "north" : __DIR__"luoyan25",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huawuxie.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
