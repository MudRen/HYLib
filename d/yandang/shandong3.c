// Room: /d/yandang/shandong3.c

inherit ROOM;

void create()
{
	set("short", "���鶴");
	set("long", @LONG
���뺬�鶴,����ϸ�ۿ��Ļ�,����ʯ���Ͽ���һ���޴��̫��ͼ,
������������,�����е��Ĺ�ã����,�߽�ȥ,ȴһ������,��˵���ǵ�
����������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"shandong4",
  "westdown" : __DIR__"shandong1",
]));

	setup();
	replace_program(ROOM);
}
