// Room: /d/yandang/dongyaotai.c

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
�˴����پ���,����ɽʯ�罣,��ɫ���,��������,��������,�߲�
����.������������ңң���.�������һ��������ߵ�������.����
Σ��.������������߶���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao1",
  "west" : __DIR__"dongwai",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
