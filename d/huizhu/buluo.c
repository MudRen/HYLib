// Room: /d/huizhu/buluo.c

inherit ROOM;

void create()
{
	set("short", "���岿��");
	set("long", @LONG
�˴����������֣�һ���б���£���һ���ޱߵĲ�ԭ��Զ����ɽ����
�������֣����������֦ͷ���С�б�µ�������ϴ�һƬ�յأ���������
�����ڿյص����롣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"buluo1",
  "east" : __DIR__"shulin",
  "west" : __DIR__"shulin1",
  "south" : __DIR__"shulin2",
]));

	setup();
	replace_program(ROOM);
}
