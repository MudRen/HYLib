// Room: /d/yandang/luoyan4.c

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
  "south" : __DIR__"luoyan3",
  "north" : __DIR__"luoyan5",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/leaf.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
