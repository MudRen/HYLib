// Room: /d/yandang/luoyan23.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֣���˵�ǵ����������˴��Ϻ���������,�����Ѿ�
����С�۴�ϸ,��˼��⾫��,��Ҷ�����罣,���������������������
��,���˻س�����,���ɻ���ͯ��ʱ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luoyan40",
  "east" : __DIR__"luoyan10",
  "west" : __DIR__"luoyan24",
]));

	setup();
	replace_program(ROOM);
}
