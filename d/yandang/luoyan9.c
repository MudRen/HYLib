// Room: /d/yandang/luoyan9.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ���̳ɵĴ��,����ɽׯ��������,ÿ��Ľ��ǰ������
����ʿ���ﲻ��,·������ľɭɭ,����¥������,���ɾ���,�Ӵ˵���
��,����ɽׯ�ı�����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"luoyan17",
  "north" : __DIR__"luoyan16",
  "west" : __DIR__"luoyan7",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/puren.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
