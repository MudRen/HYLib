// Room: /d/sandboy/daotian2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��Ӳӵ�һƬ����,΢������,��������,Զ��ȥ,һƬ��ɫ,ֱ�������
��ͷ.����������ҡ����������,�����Ž���ĺ��ճ�.������һƬɹ�ȳ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "east" : __DIR__"ground",
]));

	setup();
	replace_program(ROOM);
}
