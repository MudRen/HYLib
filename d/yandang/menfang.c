// Room: /d/yandang/menfang.c

inherit ROOM;

void create()
{
	set("short", "�ŷ�");
	set("long", @LONG
����������ɽׯ���ŷ�,���еİ���Ƚϼ�,����������֮��,��
�ϰ��ż����豭,ȷ�Ǿ�����ٽѵľ�Ʒ,������Ʈ���Ų�Ҷ������,
��������мҵĻ�,���Ա���������ڵ�����.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/laowang.c" : 1,
  "/clone/money/silver.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luoyan3",
]));

	setup();
	replace_program(ROOM);
}
