//Cracked by Kafei
// Room: /d/xixia/zhulin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֣�����ȥ���󣬵���һ�߽���ȴ�·�����·������
�����ܵ�����������ڱ�����Ȼ����ô�ϵ����ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hut",
  "east" : __DIR__"garden",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
