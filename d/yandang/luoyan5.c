// Room: /d/yandang/luoyan5.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ���̳ɵĴ��,����ɽׯ��������,ÿ��Ľ��ǰ������
����ʿ���ﲻ��,·������ľɭɭ,����¥������,���ɾ���,�Ӵ˵���
��,�ɵ�����ɽׯ�Ĵ���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan4",
  "north" : __DIR__"luoyan6",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xielin.c" : 1,
     "/d/hainan/npc/man2.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
