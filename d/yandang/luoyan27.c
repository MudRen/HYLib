// Room: /d/yandang/luoyan27.c

inherit ROOM;

void create()
{
	set("short", "��һ��");
	set("long", @LONG
��һ����ׯ���Ķ�����Ů������ס��,��������С�����ಡ,������
ϲ�徻,������ׯ����������ڴ˽����ⶰС¥,ׯ�е������²�׼����,
�������������ǿ���,ֻ���˼�������,����һ������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tanger.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"luoyan28",
  "west" : __DIR__"luoyan29",
  "south" : __DIR__"luoyan26",
]));

	setup();
	replace_program(ROOM);
}
