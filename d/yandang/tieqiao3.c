// Room: /d/yandang/tieqiao3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������ߵ�������,��ʮ�����������,�������һ���
���,���ڷ紵��ɹ,�����Զ,�еĵط��Ѿ���ȱ,���¾����������,
��˵�����˵���ȥ.���Ѿ�����һ����,���Ž��²���ҡ�ε�����,�㺦
�¼���,���Ƿ��ذ�.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao4",
  "south" : __DIR__"tieqiao2",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
