// Room: /d/yandang/to_yandang2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
·�濪ʼ��ò���ôƽ��,�ӿ����ݵ�,���ߵ�ũ���Ϊ�������
����,Ũ�ܵ�������ס���˵���Ұ,ֻ�ܸо�����������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shulin",
  "west" : __DIR__"to_yandang",
  "east" : __DIR__"to_yandang3",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
