// Room: /d/jindezheng/to_qz.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qiaofu.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"lu2",
  "northeast" : "/d/quanzhen/guandao1",
]));

	setup();
	replace_program(ROOM);
}
