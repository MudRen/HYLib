// Room: /d/yandang/luoyan12.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�ӿ�������,���Ǻ�԰,һ�����ǲ��ᱻ���뵽���,԰�еĻ�ľ��
��,��������,�����Ĵ���һ����ɽ,��ȫ�����㵴ɽ����,һ��һ��,��
�������΢,��������̾Ϊ��ֹ.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan38",
  "south" : __DIR__"luoyan8",
]));

	setup();
	replace_program(ROOM);
}
