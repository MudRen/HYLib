// Room: /d/hainan/road5.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ�����͵�ɽ·,���ʱ���㲻�ò�ץ��ɽ�ٲ�������ȥ,��ʱ��,
����������ʲô��'������������',���µ�ɽ���Ե���Щ�ɶ�,���
�Բ�ע��,�ͻ�......
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"pubu",
  "eastup" : __DIR__"jueqinya",
]));

	setup();
	replace_program(ROOM);
}
