// Room: /d/yandang/luoyan3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ����ʯ���̳ɵĴ��,����ɽׯ��������,ÿ��Ľ��ǰ������
����ʿ���ﲻ��,·������ľɭɭ,����¥������,���ɾ���,�Ӵ���,��
ɽׯ���ŷ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luoyan2",
  "north" : __DIR__"luoyan4",
  "east" : __DIR__"menfang",
]));

	setup();
	replace_program(ROOM);
}
