// Room: /d/sandboy/zhulin5.c

inherit ROOM;

void create()
{
	set("short", "��΢ͤ");
	set("long", @LONG
����һ��С�ɵ���ͤ����ȫ�ø�����Ȼ�����Ӵ���ɣ������׳
���������֧��ͤ�ӵ�������ͤ��һ�����İ����ϻ����˼�֦�ʻ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin2",
  "east" : __DIR__"zhulin3",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yingwu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
