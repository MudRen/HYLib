// Room: /d/sandboy/sidehill.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
�̲������һƬɽ��,Զ��ȥ,����,�ݵ�,����,��,����һһ����,��ʯ
��,��ͷˮţ���ڳԲ�,���ߴ�����ˮ����.����һƬ����,��������һ��
ƽ����ɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"daotian3",
  "southup" : __DIR__"shandao",
]));

	setup();
	replace_program(ROOM);
}
