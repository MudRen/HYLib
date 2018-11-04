// Room: /d/yandang/luoyan38.c

inherit ROOM;

void create()
{
	set("short", "��Ȫ");
	set("long", @LONG
�Ӻ�԰���ſ������,�����Ϊ�Լ��ߴ��˵ط�,ֻ��һƬ�տ��ĵ�
��,��̫��ʯ������һ��Сˮ̶,̶����һ��ˮȪ����������ɸ�,��֮��
������,�����৵�����,������ׯ���ľ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan12.c",
  "northwest" : __DIR__"luoyan39",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/teiqiaos.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
