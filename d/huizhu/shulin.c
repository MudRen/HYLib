// Room: /d/huizhu/shulin.c

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
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shulin3",
  "southeast" : __DIR__"byriver1",
  "west" : __DIR__"buluo",
]));

	setup();
	replace_program(ROOM);
}
