// Room: /d/yanjing/huilang2.c

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
	set("outdoors", "yanjing");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huating",
  "southeast" : __DIR__"huilang1",
]));

	setup();
	replace_program(ROOM);
}
