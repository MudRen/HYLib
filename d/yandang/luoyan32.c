// Room: /d/yandang/luoyan32.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�����ֳ���,�������ߵ������ʯ,��һ��ɽ��,��Ȫˮ����������,
������ʯ,��������,ǧ����ĳ��,�ѽ���ԭ�����ص���ʯ�̻�������
��͸,�⻬�쳣.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"luoyan33",
  "southeast" : __DIR__"luoyan31",
]));

	setup();
	replace_program(ROOM);
}
