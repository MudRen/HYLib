// Room: /d/yanjing/street4.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�ֵ����ߵ���������,�����糱,�������ڸ������׵�����,�����ϴ�
һ������,����������,�������˴���ߺ������������������ҩ.���Ͽ���
����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tiejiang",
  "south" : __DIR__"street1",
  "north" : __DIR__"wangfu",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
