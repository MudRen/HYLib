// Room: /d/sandboy/daotian3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��Ӳӵ�һƬ����,΢������,��������,Զ��ȥ,һƬ��ɫ,ֱ�������
��ͷ.����������ҡ����������,�����Ž���ĺ��ճ�.��ȥ�����﹡ͨ��
С��ׯ.������һƬɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "southup" : __DIR__"sidehill",
  "north" : __DIR__"road2",
  "west" : __DIR__"daotian1",
]));

	setup();
	replace_program(ROOM);
}
