// Room: /d/yandang/luoyan22.c

inherit ROOM;

void create()
{
	set("short", "Ů����ԡ��");
	set("long", @LONG
������Ů���ӵ�ԡ��,�����̵����������ʯ,���аڵ���һֻ��
ľͰ,������ˮͰ��ð����,ϸ����,ˮ���ϻ�Ʈ�ŵ�㻨��,���õ���,
�˴����ڻ�û�б���.
LONG
	);
	set("bath_room", "1");
	set("no_fight", "1");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luoyan19",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
