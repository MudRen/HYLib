// Room: /d/huizhu/to_bj.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������Ӿ���������صĹٵ�������ͨ�������أ����߲�Զ��������
���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/lanzhouchen/jincheng",
  "southwest" : __DIR__"guandao4",
]));

	setup();
	replace_program(ROOM);
}
