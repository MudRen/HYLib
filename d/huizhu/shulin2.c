// Room: /d/huizhu/shulin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ߵ������ֲ���ï�ܣ�ֻ��ϡ��ļ��ã�Զ����ɽ�ϸ����Ű�ѩ��
��ͬ���ϰ�ɫ���Ʋʡ���������໥ײ���Ķ��������Դ���������Ұ��
����ζ�ӽ���������������������ǳǳ��һ�㡣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhanshi.c" : 3,
]));
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"buluo",
  "west" : __DIR__"linzhong",
  "east" : __DIR__"shulin3",
]));
	set("outdoors", "huizhu");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
