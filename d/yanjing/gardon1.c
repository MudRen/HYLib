// Room: /d/yanjing/gardon1.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
ǽ�����еļ��������ڷ���΢΢����,�Ӷ�������һ��С������԰��
�ļ�ɽ����Χ�ƶ���,�����Բ���������ű��ϵ�һ��÷��,��ɽ�����и�
�ض�,����ȥ�ں�����.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/houtonghai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"gardon",
  "down" : __DIR__"cave",
  "east" : __DIR__"road1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
