// Room: /d/hainan/cave.c

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
����һ��СС��ɽ��,�ıڵ���ʯ��Ϊ����Ĵ�Ϯ,���ʮ�ֹ⻬.
��������ڱ�����һ����С�Ķ���,�����Եúܺڰ�.�Ӵ����⿴,�羰
ʮ������.ż���о޴�ľ�������ߴＸʮ�ɸߵ�ˮ��.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "����������Ա���ս������Ǹ�ҪС�ö�,����㲻�����ϵ�����
�����µĻ�,�ܿ��ܽ���ȥ.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"ontree",
  "northdown" : __DIR__"cave1",
]));

	setup();
	replace_program(ROOM);
}
