// Room: /d/yanjing/huating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ͱ�����һ����ϯ,ֻ����̴ľ�Ĵ�Բ���Ժ��˼�����,������
�����������ָ���.����ߴ�����������ڷ�,���̵�ҶƬ�����ߴﻨ����
����.���м��軨����ɫ����,��������������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lingzhi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huilang2",
]));

	setup();
	replace_program(ROOM);
}
