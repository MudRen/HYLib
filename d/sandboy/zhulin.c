// Room: /d/sandboy/zhulin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ��������֣�������Ҷ��϶���µ���ɫ���⡣�Ų�̤����Ҷ��
����ϤϤ������������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhulin1",
  "east" : __DIR__"shandao2",
]));
set("outdoors","/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangsan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
