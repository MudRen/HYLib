// Room: /d/yandang/luoyan26.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
����һƬ��ƺ,�������������,�������ű�,��������,ʵ����
һ������,�ڲ�ƺ�ľ�ͷ,��һ��СС��¥��,���������������,ֻ��
վ������,�͸������޵�����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan25",
  "north" : __DIR__"luoyan27",
   //"west" : "/u/legato/yueliangmen",
]));

	setup();
	replace_program(ROOM);
}
