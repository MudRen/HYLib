// Room: /d/yandang/luoyan1.c

inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
����һ��޴����ʯ,ͨ������ɫ,ʮ�ֺ���,��˵������ʯֻ��
�㵴�˴�,����ʯ���ķ�,�ֱ���������Լһ�׵�С��ͨ���ķ�,�򶫾�
�����,�����ǽ���������������ɽׯ.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shimeng",
  "north" : __DIR__"luoyan2",
]));

	setup();
	replace_program(ROOM);
}
