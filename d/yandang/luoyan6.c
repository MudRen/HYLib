// Room: /d/yandang/luoyan6.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ʮ�ֹ���,�ݺ��ж���ʮ��,����������һ������,��ǰ�����
һ�ŵ�̫ʦ��,���Ŵ�������,����һ�������,�˴���ׯ��ƽ�����
���˺;ۼ��������������.
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 2);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan5",
  "north" : __DIR__"luoyan7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/master.c" : 1,
]));

	setup();

	replace_program(ROOM);
}
