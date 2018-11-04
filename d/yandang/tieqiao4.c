// Room: /d/yandang/tieqiao4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������ߵ�������,��ʮ�����������,�������һ���
ľ��,���ڷ紵��ɹ,�����Զ,�еĵط��Ѿ���ȱ,���¾����������,
��˵�����˵���ȥ.���Ѿ����˴�һ����,����Խ��Խ�޷�ƽ���Լ�,��
��˫���ڲ��������Ĳ���,��ǰ�����Ǻ���?
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zaimin.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tianzhu",
  "south" : __DIR__"tieqiao3",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
