// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��Ӳӵ�һƬ����,΢������,��������,Զ��ȥ,һƬ��ɫ,ֱ�������
��ͷ.����������ҡ����������,�����Ž���ĺ��ճ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "east" : __DIR__"daotian3",
]));

	setup();
	replace_program(ROOM);
}
