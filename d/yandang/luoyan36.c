// Room: /d/yandang/luoyan36.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Ｘ��ʯ��,ӭ����һ��͸���񻨳�����,�߽�ȥ,������ˮĥ
�Ĵ���ש,�������ƽ,�����ñ�����һ������ͼ,����ĳ�̨�ϰ��˼�
��С����,�޷��ǰ�����,�ܶ�¯,���ƿ֮��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"luoyan20",
  "west" : __DIR__"luoyan37",
  "south" : __DIR__"luoyan35",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yahuan.c" : 1,
  __DIR__"npc/puren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
