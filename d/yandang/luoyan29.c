// Room: /d/yandang/luoyan29.c

inherit ROOM;

void create()
{
	set("short", "Ѿ�߾�");
	set("long", @LONG
�������ź�С���Ѿ�ߵľ���,�����̵����ϺõĴ���ʯ,�����ϰ�
�Ÿ�ժ�����İ׾ջ�,�¼��Ϻ��ҹ��ż���ȹ��,�м���Ѿ��������һ��
�������ɵ�˵����ͣ.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/huier.c" : 1,
  __DIR__"npc/laner.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan27",
]));

	setup();
	replace_program(ROOM);
}
