// Room: /d/sandboy/zhulin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ�����ĵ����֣���������������������оþò�������Ҷ��
����¶�����߹�ʱ���ص�������Զ��¶����ǽһ�ǡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zhulin4",
  "south" : __DIR__"zhulin5",
  "east" : __DIR__"zhulin1",
]));
set("outdoors","/d/jiangnan");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
