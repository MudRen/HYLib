// Room: /d/yandang/luoyan20.c

inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
�ͷ�������ɽׯ�д����˵ĵط�,�����������˶�,�Լ��������Ʒ
һ��Ҫ���ܺ�.�Ա���С���ź�,���Ե�����,���о������˼�ûʲô��
��,���Ǻú�˯һ����!
LONG
	);
	set("sleep_room", "1");
	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"luoyan36",
]));
	set("no_fight", "1");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
