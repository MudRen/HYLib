// Room: /d/yandang/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
��ܽ�������,����ɽ·��ǰ,���߶��Ǹߴ������,��Ҷ�����
����������,·�Ե�Ұ�����Ʈ��,Ϧ����ɽ,һ�������ĸо���Ȼ��
��,��ɽ������,����Ϧ����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedao2",
  "north" : __DIR__"jiudian",
]));

	setup();
	replace_program(ROOM);
}
