// Room: /d/yandang/shandong4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���߽�����,�������һ��������������,��ʲô��,������ϸѰ
��,�ͻᷢ���ڶ��������˴��СС������,ԶԶ��ȥ,ֻ��һƬ����
��ѩ���Ŀ��,����һȺ��Ѫ����,���Ӱ�!
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"shandong2",
  "southeast" : __DIR__"shandong3",
  "northup" : __DIR__"shandong5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/bat.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
