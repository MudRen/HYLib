// Room: /d/menggu/caocong1.c

inherit ROOM;

void create()
{
	set("short", "�ݴ���");
	set("long", @LONG
������ߺ������ص����Ķѻ���ͷ��ȴ��һƬ����ɫ����գ�����Ƭ�ơ�
������һ�󻺣�һ�󼱣����½������죬����һ�Ż��Ρ��¹�֮��,�ݴ���
¶��ʯ��һ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"hill1",
]));

	setup();
	replace_program(ROOM);
}
