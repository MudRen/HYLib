// Room: /d/yanjing/hubian.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
ǰ��ˮ������,����һ��СС����.��ʱ������������,���в�δ���
ѩ�����ں���,������ˮ��,����һ���Ŷ���÷��,÷���ټ��ϱ���ѩ�
�����ࡣֻ��������һ���죬���߷�����ֻˮ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"to_yj1",
]));
	set("objects",([
		__DIR__"npc/man6":1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}
