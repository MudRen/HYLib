// Room: /d/yanjing/huilang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������Ӽ���һյյС�ɵĲ�������,�������С�ɵĻ�԰,һ·
����,̨ͤ¥��,��ɽ��ˮ,С�ſ���,����ʤ��,����ת�Ǵ�,һ��С�ɻ�
¥����,ȴ������������������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shatongtian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"huilang",
  "northwest" : __DIR__"huilang2",
  "north" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
