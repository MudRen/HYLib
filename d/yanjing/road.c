// Room: /d/yanjing/road.c

inherit ROOM;

void create()
{
	set("short", "����ʯС��");
	set("long", @LONG
���Ǵ����ڻ�ľ֮���һ��С��,����ɫʯ��ϸϸ���̳ɻ���,һ��
�����ڻ�ľ��Ʈ��,��������ĵط�һ�����ѵ����ڵ�������.������
������Ժ,������¶������һ��.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/binu.c" : 1,
  __DIR__"npc/puren.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhongyuan",
  "northeast" : __DIR__"road1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
