// Room: /d/yandang/luoyan10.c

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
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"luoyan7",
  "west" : __DIR__"luoyan23",
]));

	setup();
	replace_program(ROOM);
}
