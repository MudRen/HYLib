// Room: /d/yanjing/huilang.c

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
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huilang1",
  "east" : __DIR__"qianting",
]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
