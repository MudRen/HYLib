// Room: /d/yanjing/inroom.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
��Ŀ����,����֮�ﶼ�Ǵ�ľ����,�����þ���һ������ͬ���ũ��
֮��,���Ǵֲڼ�ª,���Ϲ���һ�����������ǹ,һ�Ų����˵���ͷ,����
һ�Ƿ���һ�ܷ�ɴ�õľɷĳ�.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/baoxiruo.c" : 1,
//  __DIR__"npc/clone/clothtieli.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"gardon",
]));

	setup();
	replace_program(ROOM);
}
