// Room: /d/menggu/caocong.c

inherit ROOM;

void create()
{
	set("short", "�ݴ���");
	set("long", @LONG
������ߺ������ص����Ķѻ���ͷ��ȴ��һƬ����ɫ����գ�����Ƭ�ơ�
������һ�󻺣�һ�󼱣����½������죬����һ�Ż��Ρ��¹�֮��,�ݴ���
���Ѱ�ɫ�Ķ�����ģ�����ǹ��档
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/baigu.c" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hill1",
]));

	setup();
	replace_program(ROOM);
}
